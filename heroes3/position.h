#ifndef HEROES3_POSITION_H
#define HEROES3_POSITION_H

#include <stdint.h>

namespace heroes3 {
	class Position {
	public:
		Position( );
		Position( uint16_t x, uint16_t y );

		inline int GetX( ) { return x_; };
		inline int GetY( ) { return y_; };

	private:
		uint16_t x_;
		uint16_t y_;
	};
}

#endif