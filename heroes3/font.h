#ifndef HEROES3_FONT_H
#define HEROES3_FONT_H

#include <stdint.h>

namespace heroes3 {
	class Font {
	public:
		const char* GetName( )
		{
			return reinterpret_cast< const char* >( reinterpret_cast< uint8_t* >( this ) + 0x4 );
		}
	};
}

#endif //  HEROES3_MARKER_H