#pragma once

#include "Vector.h"
#include "Color.h"
#include "gl_define.h"
#include "Texture.h"

namespace BS {

	namespace Draw
	{
		void drawPoint(const Vector2& _pos, float _size, const Color4& _col);
		void drawLine(const Vector2& _start,const Vector2& _end, float _line_width, const Color4& _col);
		void drawFillQuad(const Vector2& _center, const Vector2& _size, const Color4 _col);
		void drawQuad(const Vector2& _center, const Vector2& _size, float _line_width, const Color4 _col);
		void drawTexture(const Texture& _texture, const Vector2& _center, const Vector2& _size, const Color4 _col);
	}
}