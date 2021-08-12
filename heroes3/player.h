#ifndef HEROES3_PLAYER_H
#define HEROES3_PLAYER_H

namespace heroes3 {
	class Hero;
	class Artifact;

	class Player {
	public:
		static Player* GetPlayer( const int player_index );

		const char* GetName( );

		void SetName( const char* name );

		Hero* GetHero( const int index );

		Artifact GetArtifact( const int index );

		int GetNumHeroes( );

		static constexpr auto kMaxHeroes = 8;
	};
}

#endif //  HEROES3_PLAYER_H