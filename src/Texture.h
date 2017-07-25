#pragma once

#include "gl_define.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#include <stb_image.h>

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