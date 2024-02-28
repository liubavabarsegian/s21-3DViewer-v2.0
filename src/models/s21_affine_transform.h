#pragma once

#include "s21_matrix_oop.h"
#include "s21_viewer_parser.h"

namespace s21 {

class AffineTransform {
 public:
  AffineTransform();
  ~AffineTransform();
  s21::Matrix createTranslationMatrix(double x, double y, double z);
  s21::Matrix createScalingMatrix(double x, double y, double z);
  s21::Matrix createXRotationMatrix(double x);
  s21::Matrix createYRotationMatrix(double y);
  s21::Matrix createZRotationMatrix(double z);
  void moveModel(Parser* data, double x, double y, double z);
  void resizeModel(Parser* data, double x, double y, double z);
  void rotateModel(Parser* data, double x, double y, double z);
  long double PI = 3.14159265358979323846264338327950288419716939937510L;
};

}  // namespace s21
