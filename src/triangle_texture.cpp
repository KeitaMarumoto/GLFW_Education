//
// OpenGL1.1 Tutorial
//

#pragma once
#include <cstdio>
#include <string>

#include "Texture.h"

int main() {
	printf("M1911_コルトガバメント\n");

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

	BlueSignal::Texture image = BlueSignal::Texture("assets/ast_icon.png");
	BlueSignal::Texture image2 = BlueSignal::Texture("assets/free.jpg");


	while (!glfwWindowShouldClose(window)) 
	{
		glLoadIdentity();
		glOrtho(-400, 400, -400, 400, 0.1, 1.0);

		// フレームバッファをクリア
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);

		gluLookAt(0, 0, -5, 0, 0, 0, 0, 1, 0);
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

		image.bind();
		glDrawArrays(GL_TRIANGLES, 0, 6);

		image2.bind();
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
