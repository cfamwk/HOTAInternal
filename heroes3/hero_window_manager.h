#ifndef HEROES3_HEROWINDOWMANAGER_H
#define HEROES3_HEROWINDOWMANAGER_H

namespace heroes3 {
	class PCX;
	class Dialog;

	class HeroWindowManager {
	public:
		PCX* GetDrawBuffer( );

		//MEMBER_FIELD(int, FirstDialog, 0x50);
		//MEMBER_FIELD(int, LastDialog, 0x54);
	};
}

#endif