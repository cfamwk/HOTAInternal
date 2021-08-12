#include "hero_window_manager.h"

#include <stdint.h>

namespace heroes3 {
	PCX* HeroWindowManager::GetDrawBuffer( )
	{
		return *reinterpret_cast< PCX** >( reinterpret_cast< uint8_t* >( this ) + 0x40 );
	}
}