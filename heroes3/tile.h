#ifndef HEROES3_TILE_H
#define HEROES3_TILE_H

namespace heroes3 {
	class Position;
	class TileContent;

	class Tile {
	public:
		Position GetPosition( );
		TileContent GetContent( );
		int GetLayer( );

		static constexpr auto TILE_PIXEL_DIMENSIONS = 32;
	};
}

#endif