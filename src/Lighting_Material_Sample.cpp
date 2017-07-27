//
// OpenGLでのライティング
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
#include "Draw.h"

using namespace BS;
using namespace BS::Draw;

int main() {
  // 初期化
  if (!glfwInit()) return -1;

  // Window生成
  GLFWwindow* window = glfwCreateWindow(800,
                                        800,
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

  // これ以降OpenGLの命令が使える
  float angle = 0.0f;

  // ライティングを有効にする
  glEnable(GL_LIGHTING);
  // 0番のライトを有効にする
  glEnable(GL_LIGHT0);
  // 法線を正規化する
  glEnable(GL_NORMALIZE);
  // カリング
  glEnable(GL_CULL_FACE);

  Material material = Material(Color4(1.0f, 0.0f, 0.0f, 1.0f), 
							   Color4(1.0f, 0.0f, 0.0f, 1.0f), 
							   Color4(0.0f, 0.0f, 0.0f, 1.0f), 
							   Color4(0.8f, 0.8f, 0.8f, 1.0f), 
							   80.0f);

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // 透視変換行列を操作する
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // 透視変換行列を現在の行列に掛け合わせる
    // left, right, botton, top, near z, far z
    glFrustum(-0.1, 0.1, -0.1, 0.1, 0.2, 10.0);

    // モデルビュー行列を操作する
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // 光源の位置
    //  カレント行列により結果が決まる
    //  wの値が1.0だとポイントライトになる
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


    // 位置の移動と回転
    glTranslatef(0.0f, 0.0f, -3.0f);
	glRotatef(angle, 1.0f, 0.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.1f, 0.0f);

    angle += 1.0f;

    // これが無効になる
    glColor3f(1, 1, 1);

	material.apply();
	drawCube(Vector3(), Vector3(1, 1, 1));

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
}
