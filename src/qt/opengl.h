#ifndef OPENGL_H
#define OPENGL_H
#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <QFile>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QtOpenGL>

#include "../controllers/s21_viewer_controller.h"

// extern "C" int open_and_parse(s21_data *model, const char *filename, int
// *blocks_to_free_in_matrix); extern "C" int create_matrix(s21_matrix
// *matrix_3d, int rows, int columns);

/**
 - @brief Класс виджета отрисовки модели
 - @param pointSize - "размер вершин"
 - @param edgeSize - "размер ребер"
 - @param noVerticles - "отсутствие вершин"
 - @param dashed - "пунктирные ребра"
 - @param verticlesColor - "цвет вершин"
 - @param edgesColor - "цвет ребер"
 - @param backgroundColor - "цвет фона"
 - @param file - "файл модели"
 - @param model - "структура модели"
 */

namespace s21 {
class OpenGL : public QOpenGLWidget {
  Q_OBJECT;

 public:
  OpenGL(QWidget *parent);
  ~OpenGL();
  /**
  - @brief Функция, рисующая модель
  */
  virtual void paintGL() override;
  int pointSize;
  int edgeSize;
  bool noVerticles;
  bool circleVerticles;
  bool squareVerticles;
  bool dashed;
  QColor verticlesColor;
  QColor edgesColor;
  QColor backgroundColor;
  QString file;
  // s21_data model;
  int allocated_blocks;
  /**
  - @brief Функция записи экрана
  */
  void record();
  s21::ViewerController &controller;

 private:
  float xRot, yRot, zRot;
  QPoint mousePosition;
  virtual void initializeGL() override;
  virtual void resizeGL(int w, int h) override;
  virtual void mousePressEvent(QMouseEvent *) override;
  virtual void mouseMoveEvent(QMouseEvent *) override;
  void drawModel(float a);
  void drawVerticles();
  void drawLines();
 public slots:
};
}  // namespace s21
#endif  // OPENGL_H
