#pragma once

#include "gl_define.h"
#include <iostream>

namespace BS {
	class Texture
	{
	public:
		Texture(const char* path_);
		~Texture();
		void bind();
		void unbind();

	private:
		GLuint tex_id;
	};
}