#include "global.h"

namespace heroes3 {
	namespace functions {
		prototypes::DrawText DrawText = reinterpret_cast< prototypes::DrawText >( 0x004B51F0 );
		prototypes::RedrawPartsOfScreen RedrawPartsOfScreen = reinterpret_cast< prototypes::RedrawPartsOfScreen >( 0x00603190 );
		prototypes::LoadFont LoadFont = reinterpret_cast< prototypes::LoadFont >( 0x0055BD10 );
	}

	namespace variables {
		AdvManager*& adv_manager = *reinterpret_cast< AdvManager** >( 0x6992b8 );
		HeroWindowManager*& hero_window_manager = *reinterpret_cast< HeroWindowManager** >( 0x6992d0 );
	}
}