#include "Texture.h"
#include <stb_image.h>

BS::Texture::Texture(const char * path_)
{
	int w, h;  //幅と高さ
	int comp;  //３or４
	unsigned char* image = stbi_load(path_, &w, &h, &comp, 0);

	std::cout << "w : " << w << ", h : " << h << std::endl;

	//テクスチャを作成
	glGenTextures(1, &tex_id);
	glBindTexture(GL_TEXTURE_2D, tex_id);
	//テクスチャをOpenGLのメモリにコピー
	GLint type = (comp == 3)
		? GL_RGB
		: GL_RGBA;

	glTexImage2D(GL_TEXTURE_2D,
				 0,                 // mipmapレベル
				 type, w, h,        // 内部形式とサイズ
				 0, type,           // 境界色、形式
				 GL_UNSIGNED_BYTE,
				 image);

	//画像破棄
	stbi_image_free(image);

	glTexParameteri(GL_TEXTURE_2D,
					GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,
					GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

BS::Texture::~Texture()
{
	glDeleteTextures(1, &tex_id);
}

void BS::Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, tex_id);
}

void BS::Texture::unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
