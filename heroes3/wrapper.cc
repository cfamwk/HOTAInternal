#include "wrapper.h"

#include <cstdarg>
#include <cstdio>

#include "global.h"
#include "pcx.h"
#include "hero_window_manager.h"

#pragma warning(disable:4996) // _CRT_SECURE_NO_WARNINGS

namespace heroes3 {
	namespace wrapper {
		void DrawText( int x, int y, Font* font, int color, int flags, const char* format, ... )
		{
			char buffer[ 1024 ];

			va_list arg;
			int done;

			va_start( arg, format );
			done = vsprintf( buffer, format, arg );
			va_end( arg );

			return functions::DrawText( font, nullptr, buffer,
				variables::hero_window_manager->GetDrawBuffer( ), x, y,
				variables::hero_window_manager->GetDrawBuffer( )->GetWidth( ),
				variables::hero_window_manager->GetDrawBuffer( )->GetHeight( ), color, flags, -1 );
		}

		Font* LoadFont( const char* font_name )
		{
			return functions::LoadFont( font_name, nullptr );
		}

		void DrawPixel( int x, int y, int color )
		{
			const auto draw_buffer = heroes3::variables::hero_window_manager->GetDrawBuffer( )->GetBuffer( );
			const auto scanline_size = heroes3::variables::hero_window_manager->GetDrawBuffer( )->GetScanlineSize( );
			*reinterpret_cast< uint32_t* >( draw_buffer + y * scanline_size + 4 * x ) = color;
		}

		void DrawRectangle( int x, int y, int width, int height, int color, bool filled )
		{
			if ( filled )
			{
				for ( auto current_x = x; current_x < x + width; current_x++ )
				{
					for ( auto current_y = y; current_y < y + height; current_y++ )
					{
						DrawPixel( current_x, current_y, color );
					}
				}

				return;
			}

			for ( auto i = 0; i < width; i++ )
				DrawPixel( x + i, y, color );

			for ( auto i = 0; i < width; i++ )
				DrawPixel( x + i, y + height, color );

			for ( auto i = 0; i < height; i++ )
				DrawPixel( x, y + i, color );

			for ( auto i = 0; i < height; i++ )
				DrawPixel( x + width, y + i, color );
		}
	}
}