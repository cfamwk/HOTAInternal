#ifndef HEROES3_WRAPPER_H
#define HEROES3_WRAPPER_H

namespace heroes3 {
	class Font;
	class Player;
	class Map;

	namespace wrapper {
		void DrawText( int x, int y, Font* font, int color, int flags, const char* format, ... );
		Font* LoadFont( const char* font_name );
		void DrawPixel( int x, int y, int color );
		void DrawRectangle( int x, int y, int width, int height, int color, bool filled = false );
	}
}

#endif //  HEROES3_WRAPPER_H