#include "base_manager.h"

#include <stdint.h>

namespace heroes3 {
	BaseManager* BaseManager::GetNextManager( )
	{
		return *reinterpret_cast< BaseManager** >( reinterpret_cast< uint8_t* >( this ) + 0x4 );
	}

	BaseManager* BaseManager::GetPreviousManager( )
	{
		return *reinterpret_cast< BaseManager** >( reinterpret_cast< uint8_t* >( this ) + 0x8 );
	}

	const char* BaseManager::GetName( )
	{
		return reinterpret_cast< const char* >( reinterpret_cast< uint8_t* >( this ) + 0x14 );
	}
}