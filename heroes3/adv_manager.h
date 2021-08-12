#ifndef HEROES3_MARKER_H
#define HEROES3_MARKER_H

#include <stdint.h>

namespace heroes3 {
	class Position;
	class WorldPosition;
	class Map;

	class AdvManager {
	public:
		uint16_t GetOverviewPositionX( )
		{
			return *reinterpret_cast< uint16_t* >( reinterpret_cast< uint8_t* >( this ) + 0xE4 );
		}
		uint16_t GetOverviewPositionY( )
		{
			return *reinterpret_cast< uint16_t* >( reinterpret_cast< uint8_t* >( this ) + 0xE6 );
		}
		uint16_t GetAbsoluteTargetedTilePosition( )
		{
			return *reinterpret_cast< uint16_t* >( reinterpret_cast< uint8_t* >( this ) + 0xE8 );
		}
		int GetRelativeTargetTilePosition( )
		{
			return *reinterpret_cast< int* >( reinterpret_cast< uint8_t* >( this ) + 0xEC );
		}
		int GetFrameCount( )
		{
			return *reinterpret_cast< short* >( reinterpret_cast< uint8_t* >( this ) + 0x100 );
		}
		Map* GetMap( )
		{
			return *reinterpret_cast< Map** >( reinterpret_cast< uint8_t* >( this ) + 0x5C );
		}
	};
}

#endif //  HEROES3_MARKER_H