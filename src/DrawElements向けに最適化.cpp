//
// glDrawElementを使った描画
//

// M_PIとかを使える余ようにする
#define _USE_MATH_DEFINES
#include <cmath>
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


// 立方体の頂点の座標
GLfloat cube_vtx[] = {
  // 前
  //  x,     y,    z,
  -0.5f,  0.5f, 0.5f,
  0.5f, -0.5f, 0.5f,
  0.5f,  0.5f, 0.5f,

  -0.5f,  0.5f, 0.5f,
  -0.5f, -0.5f, 0.5f,
  0.5f, -0.5f, 0.5f,

  // 後
  -0.5f, -0.5f, -0.5f,
  0.5f,  0.5f, -0.5f,
  0.5f, -0.5f, -0.5f,

  -0.5f, -0.5f, -0.5f,
  -0.5f,  0.5f, -0.5f,
  0.5f,  0.5f, -0.5f,

  // 左
  -0.5f, -0.5f,  0.5f,
  -0.5f,  0.5f, -0.5f,
  -0.5f, -0.5f, -0.5f,

  -0.5f, -0.5f,  0.5f,
  -0.5f,  0.5f,  0.5f,
  -0.5f,  0.5f, -0.5f,

  // 右
  0.5f,  0.5f,  0.5f,
  0.5f, -0.5f, -0.5f,
  0.5f,  0.5f, -0.5f,

  0.5f,  0.5f,  0.5f,
  0.5f, -0.5f,  0.5f,
  0.5f, -0.5f, -0.5f,

  // 上
  -0.5f, 0.5f, -0.5f,
  0.5f, 0.5f,  0.5f,
  0.5f, 0.5f, -0.5f,

  -0.5f, 0.5f, -0.5f,
  -0.5f, 0.5f,  0.5f,
  0.5f, 0.5f,  0.5f,

  // 底
  -0.5f, -0.5f,  0.5f,
  0.5f, -0.5f, -0.5f,
  0.5f, -0.5f,  0.5f,

  -0.5f, -0.5f,  0.5f,
  -0.5f, -0.5f, -0.5f,
  0.5f, -0.5f, -0.5f,
};

// 立方体の頂点の法線
GLfloat cube_normal[] = {
  // 前
  // x,    y,    z,
  0.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f,

  // 後
  0.0f, 0.0f, -1.0f,
  0.0f, 0.0f, -1.0f,
  0.0f, 0.0f, -1.0f,
  0.0f, 0.0f, -1.0f,
  0.0f, 0.0f, -1.0f,
  0.0f, 0.0f, -1.0f,

  // 左
  -1.0f, 0.0f, 0.0f,
  -1.0f, 0.0f, 0.0f,
  -1.0f, 0.0f, 0.0f,
  -1.0f, 0.0f, 0.0f,
  -1.0f, 0.0f, 0.0f,
  -1.0f, 0.0f, 0.0f,

  // 右
  1.0f, 0.0f, 0.0f,
  1.0f, 0.0f, 0.0f,
  1.0f, 0.0f, 0.0f,
  1.0f, 0.0f, 0.0f,
  1.0f, 0.0f, 0.0f,
  1.0f, 0.0f, 0.0f,

  // 上
  0.0f, 1.0f, 0.0f,
  0.0f, 1.0f, 0.0f,
  0.0f, 1.0f, 0.0f,
  0.0f, 1.0f, 0.0f,
  0.0f, 1.0f, 0.0f,
  0.0f, 1.0f, 0.0f,

  // 下
  0.0f, -1.0f, 0.0f,
  0.0f, -1.0f, 0.0f,
  0.0f, -1.0f, 0.0f,
  0.0f, -1.0f, 0.0f,
  0.0f, -1.0f, 0.0f,
  0.0f, -1.0f, 0.0f,
};


// 同じ頂点と法線のインデックスを探す
// -1 の時はみつからない
int getIndex(float x, float y, float z, float nx, float ny, float nz,
             const std::vector<GLfloat>& vtx,
             const std::vector<GLfloat>& normal) {
  for (int i = 0; i < (vtx.size() / 3); ++i) {
    if (vtx[i * 3 + 0] == x
        && vtx[i * 3 + 1] == y
        && vtx[i * 3 + 2] == z
        && normal[i * 3 + 0] == nx
        && normal[i * 3 + 1] == ny
        && normal[i * 3 + 2] == nz) {
      // 全部一致した!!
      return i;
    }
  }

  return -1;
}


// 8-19 14:00


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
  // 頂点配列
  std::vector<GLfloat> vtx;
  std::vector<GLfloat> normal;
  std::vector<GLuint> index;

  // DrawElements用のデータを作成
  for (int i = 0; i < 36; ++i) {
    float x = cube_vtx[i * 3 + 0];
    float y = cube_vtx[i * 3 + 1];
    float z = cube_vtx[i * 3 + 2];
    float nx = cube_normal[i * 3 + 0];
    float ny = cube_normal[i * 3 + 1];
    float nz = cube_normal[i * 3 + 2];

    int id = getIndex(x, y, z, nx, ny, nz,
                      vtx, normal);
                         
    if (id < 0) {
      // 同じ座標と法線を持つ頂点は見つからず
      index.push_back(vtx.size() / 3);

      vtx.push_back(x);
      vtx.push_back(y);
      vtx.push_back(z);
      normal.push_back(nx);
      normal.push_back(ny);
      normal.push_back(nz);
    }
    else {
      // 見つかった!!
      index.push_back(id);
    }
  }

  glVertexPointer(3, GL_FLOAT, 0, &vtx[0]);
  glNormalPointer(GL_FLOAT, 0, &normal[0]);

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // glFrustum(-0.1, 0.1, 0.1, -0.1, 0.2, 20.0);
  // 透視変換行列を作成
  //  視野角, 縦横比, near Z, far Z
  gluPerspective(35.0, 640 / 480.0, 0.2, 20.0);

  glMatrixMode(GL_MODELVIEW);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_NORMALIZE);
  glEnable(GL_CULL_FACE);

  // 拡散光
  GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

  // 環境光
  GLfloat ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

  // スペキュラ
  GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

  // くるくる回す
  float r = 0.0;

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    // 光源の位置
    //  カレント行列により結果が決まる
    //  wの値が1.0だとポイントライトになる
    GLfloat position[] = { 0.0f, 0.0f, 1.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glTranslatef(0, 0, -5.0);
    glRotatef(r, 0, 1, 0);
    glRotatef(r, 1, 0, 0);
    r += 1.0;

    // 頂点番号配列を使った描画
    glDrawElements(GL_TRIANGLES, index.size(), GL_UNSIGNED_INT, &index[0]);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
}
