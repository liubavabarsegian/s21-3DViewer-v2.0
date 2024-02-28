#ifndef VIEWER_VIEW_H
#define VIEWER_VIEW_H

#include <qgifimage.h>

#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QTimer>

#include "opengl.h"
namespace Ui {
class ViewerView;
}

namespace s21 {
class ViewerView : public QMainWindow {
  Q_OBJECT

 public:
  explicit ViewerView(QWidget *parent = nullptr);
  ~ViewerView();

 private:
  Ui::ViewerView *ui;
  QGifImage *gif;
  QImage *frame;
  QTimer *timer;
  int count;
 public slots:
  /**
- @brief Функция округления вершин
*/
  void circleVerticles();
  /**
- @brief Функция, делающая вершины квадратными
*/
  void squareVerticles();
  /**
- @brief Функция отмены вершин
*/
  void noVerticles();
  /**
- @brief Функция регулирования размера вершин
*/
  void resizeVerticles();
  /**
- @brief Функция регулирования толщины ребер
*/
  void resizeEdges();
  /**
- @brief Функция, делающая ребра сплошными
*/
  void edgesSolid();
  /**
- @brief Функция, делающая ребра пунктирными
*/
  void edgesDashed();
  /**
- @brief Функция для выбора цвета вершин
*/
  void verticlesColor();
  /**
- @brief Функция для выбора цвета ребер
*/
  void edgesColor();
  /**
- @brief Функция для выбора цвета фона
*/
  void backgroundColor();
  /**
- @brief Функция выбора файла
*/
  void inputFile();
  /**
- @brief Функция открытия файла
*/
  void openFile();
  /**
- @brief Функция начала записи гифки
*/
  void record();
  /**
- @brief Функция сохранения гифки
*/
  void save();
  /**
- @brief Функция сохранения скриншота
*/
  void saveImage();
  /**
- @brief Функция масштабирования модели
*/
  void resizeModel(double scale);
  /**
- @brief Функция поворотов модели
*/
  void rotateModel(double x, double y, double z);
  /**
- @brief Функция перемещения модели
*/
  void moveModel(double x, double y, double z);
  void toCentralProjection();
  void toParallelProjection();
};
}  // namespace s21
#endif  // VIEWER_VIEW_H
