#pragma once
#include "gl_define.h"

namespace BS 
{
	class Color4 
	{
	public:
		Color4()
			:r(0),g(0),b(0),a(0)
		{}
		Color4(float _r, float _g, float _b, float _a)
			:r(_r), g(_g), b(_b), a(_a)
		{}

		inline static Color4 black() { return Color4(0, 0, 0, 1); }
		inline static Color4 white() { return Color4(1, 1, 1, 1); }

		inline static Color4 red() { return Color4(1, 0, 0, 1); }
		inline static Color4 green() { return Color4(0, 1, 0, 1); }
		inline static Color4 blue() { return Color4(0, 0, 1, 1); }

		inline static Color4 magenta() { return Color4(1, 0, 1, 1); }
		inline static Color4 cyan() { return Color4(0, 1, 1, 1); }

		GLfloat* toArray() 
		{
			GLfloat data[] =
			{
				r, g, b, a
			};

			return data;
		}

		float r, g, b, a;
	};
}