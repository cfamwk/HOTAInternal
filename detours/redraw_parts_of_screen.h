#ifndef DETOURS_REDRAW_PARTS_OF_SCREEN_H
#define DETOURS_REDRAW_PARTS_OF_SCREEN_H

#include <memory>

#include "../utility/event_handler.h"
#include "..//utility/jmp_detour.h"
#include "../heroes3/global.h"

namespace detours {
	class RedrawPartsOfScreen : public utility::JMPDetour {
	public:
		RedrawPartsOfScreen( );

		inline static utility::EventHandler<int&, int&, int&, int&> Event;

	private:
		static void __fastcall Handler( void* ECX, void* EDX, int x, int y, int width, int height );

		inline static heroes3::prototypes::RedrawPartsOfScreen original_;
	};
}

#endif //  DETOURS_REDRAW_PARTS_OF_SCREEN_H
