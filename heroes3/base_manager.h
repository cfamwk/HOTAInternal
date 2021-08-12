#ifndef HEROES3_BASE_MANAGER_H
#define HEROES3_BASE_MANAGER_H

namespace heroes3 {
	class BaseManager {
	public:
		BaseManager* GetNextManager( );
		BaseManager* GetPreviousManager( );
		const char* GetName( );
	};
}

#endif //  HEROES3_BASE_MANAGER_H