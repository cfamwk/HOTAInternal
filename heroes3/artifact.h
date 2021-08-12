#ifndef HEROES3_ARTIFACT_H
#define HEROES3_ARTIFACT_H

namespace heroes3 {
	class Hero;
	class Artifact;

	class Artifact {
	public:
		const char* GetName( );

		static constexpr auto kMaxHeroes = 8;
	};
}
#endif //  HEROES3_ARTIFACT_H