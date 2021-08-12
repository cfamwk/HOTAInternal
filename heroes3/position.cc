#include "position.h"

namespace heroes3 {
	Position::Position( )
		: x_( 0 ), y_( 0 )
	{
	}

	Position::Position( uint16_t x, uint16_t y )
		: x_( x ), y_( y )
	{
	}
}