#include "jmp_detour.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "../utility/thirdparty/ldasm.h"

	namespace utility {
		JMPDetour::JMPDetour( void* src, void* dst, void* original )
			: src_( reinterpret_cast< uint8_t* >( src ) ), dst_( reinterpret_cast< uint8_t* >( dst ) )
		{
			DWORD old_protect = 0;
			ldasm_data data = { 0 };

			//Deprotect page
			VirtualProtect( src_, kByteSizeOfDetour, PAGE_EXECUTE_READWRITE, &old_protect );

			//store original bytes
			do
			{
				const auto tmp = src_ + original_bytes_.size( );

				for ( size_t i = 0; i < ldasm( tmp, &data, _WIN32 ); i++ )
					original_bytes_.push_back( tmp[ i ] );
			} while ( original_bytes_.size( ) < kByteSizeOfDetour );

			//Setup 'original' function
			detour_buffer_ = reinterpret_cast< uint8_t* >( VirtualAlloc( NULL, 0x1000, MEM_COMMIT, PAGE_EXECUTE_READWRITE ) );

			std::copy( original_bytes_.begin( ), original_bytes_.end( ), detour_buffer_ ); // original code

			for ( size_t instruction_index = 0; instruction_index < original_bytes_.size( );) // relocate original code
			{
				const auto current_instruction = detour_buffer_ + instruction_index;
				const auto delta = src_ - detour_buffer_;

				const auto size_of_instruction = ldasm( dst_ + instruction_index, &data, false );

				if ( data.flags & F_RELATIVE )
				{
					if ( data.imm_size == 2 )
						*reinterpret_cast< int16_t* >( current_instruction + data.imm_offset ) += delta;

					if ( data.imm_size == 4 )
						*reinterpret_cast< int32_t* >( current_instruction + data.imm_offset ) += delta;
				}

				instruction_index += size_of_instruction;
			}

			WriteJump( detour_buffer_ + original_bytes_.size( ), src_ + original_bytes_.size( ) ); // write jump from detour buffer to src + original_bytes

			*reinterpret_cast< void** >( original ) = detour_buffer_;

			WriteJump( src_, dst_ ); // write jump from src to dst

			//Restore original page protection
			VirtualProtect( src_, kByteSizeOfDetour, old_protect, &old_protect );
		}
		JMPDetour::~JMPDetour( )
		{
			DWORD old_protect = 0;

			VirtualProtect( src_, original_bytes_.size( ), PAGE_EXECUTE_READWRITE, &old_protect );

			memcpy( src_, original_bytes_.data( ), original_bytes_.size( ) );

			VirtualProtect( src_, original_bytes_.size( ), old_protect, &old_protect );

			VirtualFree( detour_buffer_, kByteSizeOfDetour, MEM_FREE );
		}

		void JMPDetour::WriteJump( uint8_t* src, uint8_t* dst )
		{
			unsigned char patch[ ] { 0xe9,0,0,0,0 };

			*( void** ) ( &patch[ 1 ] ) = ( unsigned char* ) ( ( unsigned char* ) dst - ( ( unsigned char* ) src + sizeof( patch ) ) );

			memcpy( src, patch, sizeof( patch ) );
		}
	}
