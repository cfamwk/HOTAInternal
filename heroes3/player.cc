#include "player.h"

#include "global.h"
#include "artifact.h"

namespace heroes3 {
	Player* Player::GetPlayer( const int player_index )
	{
		return nullptr;
	}
	const char* Player::GetName( )
	{
		throw "not implemented";
	}

	void Player::SetName( const char* name )
	{
		throw "not implemented";
	}

	Hero* Player::GetHero( const int index )
	{
		throw "not implemented";
	}

	Artifact Player::GetArtifact( const int index )
	{
		return Artifact( );
	}

	int Player::GetNumHeroes( )
	{
		return 0;
	}
}