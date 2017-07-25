#pragma once

#include "Vector.h"
#include "Color.h"
#include "gl_define.h"

namespace BS {

	namespace Draw
	{
		void drawPoint(const Vector2& _pos, float _size, const Color4& _col);
		void drawLine();
		void drawQuad();
		void drawTexture();
	}
}