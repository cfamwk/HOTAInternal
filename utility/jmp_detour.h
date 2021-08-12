#ifndef HEROES3_JMP_DETOUR_H
#define HEROES3_JMP_DETOUR_H

#include <vector>

#include "base_detour.h"

namespace utility {
	class JMPDetour : public BaseDetour {
	public:
		JMPDetour( void* src, void* dst, void* original );

		~JMPDetour( );

	private:
		void WriteJump( uint8_t* src, uint8_t* dst );

		uint8_t* dst_, * src_, * detour_buffer_;
		std::vector<uint8_t> original_bytes_;
		static constexpr auto kByteSizeOfDetour = 5;
	};
}

#endif //  HEROES3_JMP_DETOUR_H
