//
// OBJ形式を扱う
//

// M_PIとかを使える余ようにする
#define _USE_MATH_DEFINES
#include <cmath>
#include <fstream>
#include <cassert>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>


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

std::vector<GLfloat> nor;
std::vector<GLfloat> vtx;
std::vector<GLfloat> tex;
std::vector<GLuint> face;

// OBJ形式を読み込む
void loadObj() {
  std::ifstream stream("assets/box.obj");
  assert(stream);

  while (!stream.eof()) {
    // セクションを探す
    std::string s;
    std::getline(stream, s);


    if (s == "# normals") {
      std::cout << "normals" << std::endl;
	  
	  while(!s.empty()) {
		  std::string title;
		  float x, y, z;
		  std::getline(stream, s);
		  std::stringstream ss(s);

		  ss >> title >> x >> y >> z;

		  nor.push_back(x);
		  nor.push_back(y);
		  nor.push_back(z);
	  }
    }
    else if (s == "# texcoords") {
      std::cout << "texcoords" << std::endl;
	  while (!s.empty()) {
		  std::string title;
		  float x, y;
		  std::getline(stream, s);
		  std::stringstream ss(s);

		  //ss >> title;
		  ss >> title >> x >> y;

		  tex.push_back(x);
		  tex.push_back(y);
	  }
    }
    else if (s == "# verts") {
      std::cout << "verts" << std::endl;
	  while (!s.empty()) {
		  std::string title;
		  float x, y, z;
		  std::getline(stream, s);
		  std::stringstream ss(s);

		  //ss >> title;
		  ss >> title >> x >> y >> z;

		  vtx.push_back(x);
		  vtx.push_back(y);
		  vtx.push_back(z);
	  }
    }
    else if (s == "# faces") {
      std::cout << "faces" << std::endl;
	  while (!s.empty()) {
		  std::string title, x, y, z;
		  std::getline(stream, s);
		  std::stringstream ss(s);

		  ss >> title >> x >> y >> z;
		  for (int i = 0; i < 3; i++) {

		  }
		  std::cout << "(" << x <<", " << y << ", " << z << ")" << std::endl;
	  }
    }
  }
}


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

  // これ以降OpenGLの命令が使える
  loadObj();

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
}
