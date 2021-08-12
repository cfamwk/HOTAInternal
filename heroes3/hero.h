#ifndef HEROES3_HERO_H
#define HEROES3_HERO_H

namespace heroes3 {
	class Artifact;

	class Hero {
	public:
		const char* GetName( );

		void SetName( const char* name );

		int GetBaseMovementPoints( );

		int SetBaseMovementPoints( const int movement_points );

		int GetMovementPoints( );

		void SetMovementPoints( const int movement_points );

		Artifact GetArtifact( const int index );

		static constexpr auto kMaxArtifacts = 20;
	};
}

#endif