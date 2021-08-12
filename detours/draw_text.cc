#include "draw_text.h"

#include "../heroes3/global.h"
#include "../heroes3/wrapper.h"

namespace detours {
	DrawText::DrawText( )
		: JMPDetour( heroes3::functions::DrawText, Handler, &original_ )
	{
	}
	void __fastcall DrawText::Handler( void* font, void* edx, const char* text, void* draw_buffer, int x, int y, int frame_width, int frame_height, int color, int flags, int mode /*-1 or 1*/ )
	{
		original_( font, nullptr, text, draw_buffer, x, y, frame_width, frame_height, color, flags, mode );
	}
}