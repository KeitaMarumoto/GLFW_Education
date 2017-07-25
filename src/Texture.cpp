#include "Texture.h"
#include <stb_image.h>

BS::Texture::Texture(const char * path_)
{
	int w, h;  //���ƍ���
	int comp;  //�Ror�S
	unsigned char* image = stbi_load(path_, &w, &h, &comp, 0);

	std::cout << "w : " << w << ", h : " << h << std::endl;

	//�e�N�X�`�����쐬
	glGenTextures(1, &tex_id);
	glBindTexture(GL_TEXTURE_2D, tex_id);
	//�e�N�X�`����OpenGL�̃������ɃR�s�[
	GLint type = (comp == 3)
		? GL_RGB
		: GL_RGBA;

	glTexImage2D(GL_TEXTURE_2D,
				 0,                 // mipmap���x��
				 type, w, h,        // �����`���ƃT�C�Y
				 0, type,           // ���E�F�A�`��
				 GL_UNSIGNED_BYTE,
				 image);

	//�摜�j��
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
