#pragma once

#include "gl_define.h"

#include <iostream>

namespace BS {
	class Texture
	{
	public:
		Texture(const char* path_);
		~Texture();
		void bind() const;
		void unbind() const;

	private:
		GLuint tex_id;
	};
}