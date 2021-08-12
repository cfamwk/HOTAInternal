#include "redraw_parts_of_screen.h"

namespace detours {
	RedrawPartsOfScreen::RedrawPartsOfScreen( )
		: utility::JMPDetour( heroes3::functions::RedrawPartsOfScreen, Handler, &original_ )
	{
	}

	void __fastcall RedrawPartsOfScreen::Handler( void* ECX, void* EDX, int x, int y, int width, int height )
	{
		original_( ECX, EDX, x, y, width, height );
	}
}