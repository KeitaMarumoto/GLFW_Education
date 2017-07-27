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

    // 頂点配列を用意
    //  立方体の頂点配列
    GLfloat vtx[] = {
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

    // 頂点データ情報をOpenGLへ送る
    // 引数: 次元数(2とか3とか)
    //       型(FLOATとかINTとか)
    //       ??(だいたい0)
    //       配列の先頭位置
    glVertexPointer(3, GL_FLOAT, 0, vtx);

    // 立方体の面法線
    GLfloat normal[] = {
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
    // 法線データ情報をOpenGLへ送る
    // 引数: 型(FLOATとかINTとか)
    //       ??(だいたい0)
    //       配列の先頭位置
    glNormalPointer(GL_FLOAT, 0, normal);

    // これが無効になる
    glColor3f(1, 1, 1);

    // マテリアル(材質)の設定
    //  環境光が当たった時の色味
    GLfloat mat_amb[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_amb);

    // 拡散光が当たった時の色味
    GLfloat mat_diff[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diff);

    // 自己発光
    GLfloat mat_emi[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emi);

    // 光沢の色味
    GLfloat mat_spe[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spe);

    // 光沢の加減
    //  値が小さいほど鋭い光沢になる
    GLfloat mat_shin = 80.0f;
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mat_shin);

    // 頂点配列を使うよ!!
    glEnableClientState(GL_VERTEX_ARRAY);
    // 法線配列を使うよ!!
    glEnableClientState(GL_NORMAL_ARRAY);

    // 頂点配列と法線配列を使って三角形を描画
    glDrawArrays(GL_TRIANGLES, 0, 36);

    // もう使わない...
    glDisableClientState(GL_VERTEX_ARRAY);
    // もう使わない...
    glDisableClientState(GL_NORMAL_ARRAY);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
}
