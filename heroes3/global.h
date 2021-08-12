#ifndef HEROES3_GLOBAL_H
#define HEROES3_GLOBAL_H

namespace heroes3 {
	class AdvManager;
	class HeroWindowManager;
	class Font;

	enum TextColors {
		TEXTCOLOR_LIGHTBLUE = 0, TEXTCOLOR_WHITE = 1, TEXTCOLOR_LIGHTGOLDEN = 2,
		TEXTCOLOR_DARKGOLDEN = 3, TEXTCOLOR_GREEN = 13, TEXTCOLOR_LIGHTGREEN = 14, TEXTCOLOR_DARKGREEN = 15,
		TEXTCOLOR_BLACK = 23, TEXTCOLOR_DARKBLUE = 24, TEXTCOLOR_LIGHTGREEN_2 = 25, TEXTCOLOR_TEAL = 26, TEXTCOLOR_RED = 27,
		TEXTCOLOR_PINK = 28, TEXTCOLOR_YELLOW = 29, TEXTCOLOR_GRAY = 30, TEXTCOLOR_DIMBLUE = 56, TEXTCOLOR_BROWN = 57,
		TEXTCOLOR_DIMGREEN = 58, TEXTCOLOR_ORANGE = 59, TEXTCOLOR_DIMPURPLE = 60, TEXTCOLOR_CYAN = 61,
		TEXTCOLOR_DIMPINK = 62, TEXTCOLOR_DIMYELLOW = 89, TEXTCOLOR_DIMMERYELOW = 90, TEXTCOLOR_EVENDIMMERYELLOW = 91
	};
	enum TextFlags { TEXTFLAG_CENTER = ( 1 << 0 ), TEXTFLAG_ALIGN_RIGHT = ( 1 << 1 ), TEXTFLAG_ALIGNBOTTOM = ( 1 << 2 ), TEXTFLAG_NODRAW = ( 1 << 3 ) };

	namespace prototypes {
		typedef void( __fastcall* DrawText )( void* font, void* EDX, const char* text, void* draw_buffer, int x, int y, int frame_height, int frame_width, int color, int flags, int mode /*-1 or 1*/ );
		typedef void( __fastcall* RedrawPartsOfScreen )( void* ECX, void* EDX, int x, int y, int width, int height );
		typedef Font* ( __fastcall* LoadFont )( const char* ECX, void* EDX );
	}

	namespace functions {
		extern prototypes::DrawText DrawText;
		extern prototypes::RedrawPartsOfScreen RedrawPartsOfScreen;
		extern prototypes::LoadFont LoadFont;
	}

	namespace variables {
		extern AdvManager*& adv_manager;
		extern HeroWindowManager*& hero_window_manager;
	}
}

#endif //  HEROES3_GLOBAL_H