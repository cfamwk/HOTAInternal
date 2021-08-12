#ifndef HEROES3_MAP_POSITION_H
#define HEROES3_MAP_POSITION_H

#include <stdint.h>

namespace heroes3 {
	class WorldPosition {
	public:
		WorldPosition( );

		inline uint16_t GetX( ) { return x_; }
		inline uint16_t GetY( ) { return y_; }
		inline uint16_t GetLayer( ) { return layer_; }

	private:
		uint16_t x_;
		uint16_t y_;
		uint16_t layer_;
	};
}

#endif //  HEROES3_MAP_POSITION_H