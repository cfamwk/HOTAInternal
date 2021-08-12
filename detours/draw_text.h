#ifndef DETOURS_DRAW_TEXT_H
#define DETOURS_DRAW_TEXT_H

#include <memory>

#include "../utility/event_handler.h"
#include "../utility/jmp_detour.h"
#include "../heroes3/global.h"

namespace detours {
	class DrawText : public utility::JMPDetour {
	public:
		DrawText( );

		inline static utility::EventHandler<void*&, const char*&, int&, int&, int&, int&, int&, int&, int&> Event;

	private:
		static void __fastcall Handler( void* font, void* edx, const char* text, void* drawBuffer, int x, int y, int dx, int dy, int color, int flags, int mode );

		inline static heroes3::prototypes::DrawText original_;
	};
}

#endif //  DETOURS_DRAW_TEXT_H
