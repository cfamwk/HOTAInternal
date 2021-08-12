#pragma once

#include <list>
#include <functional>

	namespace utility {
		template <typename ... Args>
		class EventHandler
		{
		public:
			void operator()( Args ... args ) const
			{
				for ( const auto& callback : callbacks )
					callback( std::forward<Args>( args )... );
			}

			void operator+=( std::function<void( Args... )> callback )
			{
				callbacks.push_back( callback );
			}

			void operator-=( std::function<void( Args... )> callback )
			{
				//callbacks.remove(callback);
			}

		private:
			std::list<std::function<void( Args... )>> callbacks;
		};
	}
