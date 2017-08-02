//
// glDrawElementを使った描画
//

// M_PIとかを使える余ようにする
#define _USE_MATH_DEFINES
#include <cmath>

// GLFWのヘッダ内で他のライブラリを取り込む
#define GLFW_INCLUDE_GLEXT
#define GLFW_INCLUDE_GLU

#if defined(_MSC_VER)
// Windows:GLEWをスタティックライブラリ形式で利用
#define GLEW_STATIC
#include <GL/glew.h>
#endif
#include <GLFW/glfw3.h>


#if defined(_MSC_VER)
// Windows:外部ライブラリのリンク指定
#if defined (_DEBUG)
#pragma comment(lib, "glfw3d.lib")
#pragma comment(lib, "glew32sd.lib")
#else
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#endif
#pragma comment(lib, "OPENGL32.lib")
#pragma comment(lib, "GLU32.lib")
#endif

#include "Material.h"
using namespace BS;

int main() {
  // 初期化
  if (!glfwInit()) return -1;

  // Window生成
  GLFWwindow* window = glfwCreateWindow(800,
                                        600,
                                        "OpenGL lighthing",
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

  Material mat = Material(Color4(1, 0, 0, 1), Color4(1, 0.2f, 0.2f, 1), Color4(0, 0, 0, 0), Color4(1, 1, 1, 1), 70.0f);

  // ライティングを有効にする
  glEnable(GL_LIGHTING);
  // 0番のライトを有効にする
  glEnable(GL_LIGHT0);
  glEnable(GL_NORMALIZE);
  glEnable(GL_CULL_FACE);
  // これ以降OpenGLの命令が使える
  // 頂点配列
  GLfloat vtx[] = {
    -1,  1,  1,
    -1, -1,  1,
     1, -1,  1,
     1,  1,  1,
    -1,  1, -1,
    -1, -1, -1,
     1, -1, -1,
     1,  1, -1,
  };
  glVertexPointer(3, GL_FLOAT, 0, vtx);

  GLubyte col[] = { 255,0,0,255,	255,0,0,255,	255,0,0,255,	255,0,0,255,	// +X = red
					0,255,0,255,	0,255,0,255,	0,255,0,255,	0,255,0,255,	// +Y = green
					0,0,255,255,	0,0,255,255,	0,0,255,255,	0,0,255,255,	// +Z = blue
					0,255,255,255,	0,255,255,255,	0,255,255,255,	0,255,255,255,	// -X = cyan
					255,0,255,255,	255,0,255,255,	255,0,255,255,	255,0,255,255,	// -Y = purple
					255,255,0,255,	255,255,0,255,	255,255,0,255,	255,255,0,255 };
  glColorPointer(4, GL_UNSIGNED_BYTE, 0, col);

  // 頂点番号配列
  GLuint index[] = {
    0, 1, 2,
    0, 2, 3,
    7, 6, 5,
    7, 5, 4,
    3, 2, 6,
    3, 6, 7,
    4, 5, 1,
    4, 1, 0,
    4, 0, 3,
    4, 3, 7,
    1, 5, 6,
    1, 6, 2
  };

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glEnableClientState(GL_VERTEX_ARRAY);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // glFrustum(-0.1, 0.1, 0.1, -0.1, 0.2, 20.0);
  // 透視変換行列を作成
  //  視野角, 縦横比, near Z, far Z
  gluPerspective(35.0, 640 / 480.0, 0.2, 20.0);

  glMatrixMode(GL_MODELVIEW);

  GLfloat position[] = { 0.0f, 0.0f, 1.0f, 0.0f };
  glLightfv(GL_LIGHT0, GL_POSITION, position);

  // 拡散光
  GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

  // 環境光
  GLfloat ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

  // スペキュラ
  GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

  float r = 0.0;

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0, 0, -5.0);
    //glRotatef(r, 0, 1, 0);
    glRotatef(r, 1, 0, 0);
    r += 1.0;

	//glEnableClientState(GL_COLOR_ARRAY);

    // 頂点番号配列を使った描画
	//glColor4f(1, 1, 1, 1);
	mat.apply();
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, index);
	//glDisableClientState(GL_COLOR_ARRAY);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
}
