#ifndef HEROES3_PCX_H
#define HEROES3_PCX_H

#include <stdint.h>

namespace heroes3 {
	class PCX {
	public:
		int GetHeight( );
		int GetWidth( );
		int GetBufferSize( );
		int GetScanlineSize( );
		uint8_t* GetBuffer( );
	};
}

#endif //  HEROES3_PCX_H