#include "opengl.h"

namespace s21 {
OpenGL::OpenGL(QWidget *parent)
    : QOpenGLWidget(parent), controller(s21::ViewerController::getInstance()) {
  qDebug("init opengl\n");
  pointSize = 10;
  edgeSize = 5;
  noVerticles = false;
  dashed = false;
  backgroundColor = Qt::white;
}

OpenGL::~OpenGL() {}

void OpenGL::initializeGL() {
  // преобразование матрицы так, чтобыe
  // создавалась ортогональная проекци
  if (file.size() > 0) {
    controller.Parse(file.toStdString());
  }
  //   glOrtho(0, 800, 0, 600, 1, 100);
}

void OpenGL::paintGL() {
  glClearColor(backgroundColor.redF(), backgroundColor.greenF(),
               backgroundColor.blueF(), 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  //     загрузка в стек единичной матрицы
  glLoadIdentity();
  glRotatef(xRot, 1, 0, 0);
  glRotatef(yRot, 0, 1, 0);
  glScalef(0.01, 0.01, 0.01);

  glPointSize(pointSize);
  if (noVerticles == false) {
    if (circleVerticles == true) glEnable(GL_POINT_SMOOTH);
    if (squareVerticles == true) glDisable(GL_POINT_SMOOTH);
    glColor3d(verticlesColor.redF(), verticlesColor.greenF(),
              verticlesColor.blueF());
    drawVerticles();
  }

  glLineWidth(edgeSize);
  if (dashed) {
    glLineStipple(10, 0xAAAA);
    glEnable(GL_LINE_STIPPLE);
  } else
    glDisable(GL_LINE_STIPPLE);
  glColor3d(edgesColor.redF(), edgesColor.greenF(), edgesColor.blueF());
  drawLines();
}

void OpenGL::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void OpenGL::drawVerticles() {
  // рисует вершины
  //  glBegin(GL_POINTS);
  //  for (unsigned int i = 0; i < controller.GetMatrix3DRows(); i++) {
  //      double x = controller.GetMatrix()[i][0];
  //      double y = controller.GetMatrix()[i][1];
  //      double z = controller.GetMatrix()[i][2];
  //      glVertex3d(x, y, z);
  //  }
  //  glEnd();

  // Создание буфера вершин
  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

  // Копирование данных из Matrix в стандартный массив
  std::vector<GLfloat> vertices;
  for (unsigned int i = 0; i < controller.GetMatrix3DRows(); i++) {
    double x = controller.GetMatrix()[i][0][0];
    double y = controller.GetMatrix()[i][0][1];
    double z = controller.GetMatrix()[i][0][2];
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(z);
    // qDebug("verticles: x %f y %f z %f", x, y, z);
  }

  // Загрузка данных в буфер вершин
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertices.size(),
               vertices.data(), GL_STATIC_DRAW);

  // Указание формата данных вершин
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, 0);

  // Отрисовка вершин
  glColor3d(verticlesColor.redF(), verticlesColor.greenF(),
            verticlesColor.blueF());
  glDrawArrays(GL_POINTS, 0, vertices.size() / 3);

  // Очистка
  glDisableClientState(GL_VERTEX_ARRAY);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glDeleteBuffers(1, &vertexBuffer);
}
void OpenGL::drawLines() {
  // соединяет линии по точкам подряд
  for (size_t i = 0; i < controller.GetPolygons().size(); i++) {
    glBegin(GL_LINE_LOOP);
    for (size_t j = 0; j < controller.GetPolygons()[i].size(); j++) {
      int polygon = controller.GetPolygons()[i][j];
      double x = controller.GetMatrix()[polygon][0][0];
      double y = controller.GetMatrix()[polygon][0][1];
      double z = controller.GetMatrix()[polygon][0][2];
      if (i == 0 && j == 0) {
        qDebug("x %f y %f z %f", x, y, z);
        qDebug();
      }
      glVertex3f(x, y, z);
    }
    glEnd();
  }
}

void OpenGL::mousePressEvent(QMouseEvent *mo) { mousePosition = mo->pos(); }

void OpenGL::mouseMoveEvent(QMouseEvent *mo) {
  xRot = 1 / M_PI * (mo->pos().y() - mousePosition.y());
  yRot = 1 / M_PI * (mo->pos().x() - mousePosition.x());
  update();
}

};  // namespace s21
