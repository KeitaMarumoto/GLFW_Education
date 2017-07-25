
#pragma once
#include <cstdio>
#include <string>
#include "Texture.h"
#include "Draw.h"

using namespace BS::Draw;
using namespace BS;

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

	Texture image = Texture("assets/ast_icon.png");
	Texture image2 = Texture("assets/free.jpg");

	glViewport(0, 0, 800, 800);
	glOrtho(-400, 400, -400, 400, -1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	while (!glfwWindowShouldClose(window)) 
	{
		// フレームバッファをクリア
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//座標軸描画
		{
			drawLine(Vector2(400, 0), Vector2(-400, 0), 2.0f, Color4(1, 0.4, 0.4, 1));
			drawLine(Vector2(0, 400), Vector2(0, -400), 2.0f, Color4(0.4, 1, 0.4, 1));
		}

		drawPoint(Vector2(-200, 200), 8.0f, Color4::green());
		drawQuad(Vector2(-200, 0), Vector2(150, 150), 1.0, Color4::cyan());
		drawFillQuad(Vector2(-200, -200), Vector2(150, 150), Color4::magenta());
		drawTexture(image, Vector2(0, 0), Vector2(150, 150), Color4::white());
		drawTexture(image2, Vector2(200, 0), Vector2(150, 150), Color4::white());

		// 表示画面と描画画面を入れ替える
		glfwSwapBuffers(window);
		// キー入力などのイベント処理
		glfwPollEvents();
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glfwTerminate();

	return 0;
}
