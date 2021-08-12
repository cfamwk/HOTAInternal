#include "pcx.h"

namespace heroes3 {
	int PCX::GetHeight( )
	{
		return *reinterpret_cast< int* >( reinterpret_cast< uint8_t* >( this ) + 0x24 );
	}

	int PCX::GetWidth( )
	{
		return *reinterpret_cast< int* >( reinterpret_cast< uint8_t* >( this ) + 0x28 );
	}

	int PCX::GetBufferSize( )
	{
		return ( GetHeight( ) + GetWidth( ) ) * 4;
	}

	int PCX::GetScanlineSize( )
	{
		return *reinterpret_cast< int* >( reinterpret_cast< uint8_t* >( this ) + 0x2C );
	}

	uint8_t* PCX::GetBuffer( )
	{
		return *reinterpret_cast< uint8_t** >( reinterpret_cast< uint8_t* >( this ) + 0x30 );
	}
}