//
// OpenGL1.1 Tutorial
//

#pragma once
#include <cstdio>
#include <string>
#include "gl_define.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#include <stb_image.h>
#include <iostream>

int main() {
	// 初期化
	if (!glfwInit()) return -1;

	// Window生成
	GLFWwindow* window = glfwCreateWindow(800,
										  800,
										  "OpenGL template",
										  nullptr, nullptr);

	if (!window) {
		// 生成失敗
		glfwTerminate();
		return -1;
	}

	// OpenGLをWindowで使えるようにする
	glfwMakeContextCurrent(window);
	// Window画面の更新タイミングをPCディスプレイに同期する
	glfwSwapInterval(1);

#if defined (_MSC_VER)
	// GLEWを初期化(Windows)
	if (glewInit() != GLEW_OK) {
		// パソコンがOpenGL拡張に対応していなければ終了
		glfwTerminate();
		return -1;
	}
#endif

	//BS::Texture image = BS::Texture("assets/ast_icon.png");
	//BS::Texture image2 = BS::Texture("assets/free.jpg");

	GLuint tex_id;
	GLuint tex_id2;
	{
		int w, h;  //幅と高さ
		int comp;  //３or４
		unsigned char* image = stbi_load("assets/ast_icon.png", &w, &h, &comp, 0);

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
	{
		int w, h;  //幅と高さ
		int comp;  //３or４
		unsigned char* image = stbi_load("assets/free.jpg", &w, &h, &comp, 0);

		std::cout << "w : " << w << ", h : " << h << std::endl;

		//テクスチャを作成
		glGenTextures(1, &tex_id2);
		glBindTexture(GL_TEXTURE_2D, tex_id2);
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

	glViewport(0, 0, 800, 800);

	while (!glfwWindowShouldClose(window)) 
	{
		glOrtho(-400, 400, -400, 400, -1.0, 1.0);

		// フレームバッファをクリア
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//gluLookAt(0, 0, -1, 0, 0, 0, 0, 1, 0);
		//
		// 画面更新処理はここに書く
		//

		GLfloat vtx[] = { 
			-50, 50,
			-50,-50,
			 50, 50,

			 50, 50,
			-50,-50,
			 50,-50,

			-250, 50,
			-250,-50,
			-150, 50,

			-150, 50,
			-250,-50,
			-150,-50,

			 150, 50,
			 150,-50,
			 250, 50,

			 250, 50,
			 150,-50,
			 250,-50
		};

		GLfloat uv[] = {
			0.0, 0.0,
			0.0, 1.0,
			1.0, 0.0,

			1.0, 0.0,
			0.0, 1.0,
			1.0, 1.0,

			0.0, 0.0,
			0.0, 1.0,
			1.0, 0.0,

			1.0, 0.0,
			0.0, 1.0,
			1.0, 1.0,

			0.0, 0.0,
			0.0, 1.0,
			1.0, 0.0,

			1.0, 0.0,
			0.0, 1.0,
			1.0, 1.0
		};

		glVertexPointer(2, GL_FLOAT, 0, vtx);
		glTexCoordPointer(2, GL_FLOAT, 0, uv);
		
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, tex_id);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		glBindTexture(GL_TEXTURE_2D, tex_id2);
		glDrawArrays(GL_TRIANGLES, 6, 6);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);

		// 表示画面と描画画面を入れ替える
		glfwSwapBuffers(window);
		// キー入力などのイベント処理
		glfwPollEvents();
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glfwTerminate();

	return 0;
}
