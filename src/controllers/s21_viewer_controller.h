#pragma once

#include <memory>

#include "../models/s21_affine_transform.h"
#include "../models/s21_viewer_parser.h"

namespace s21 {
class ViewerController {
 public:
  static ViewerController& getInstance() {
    static ViewerController instance;
    return instance;
  }

  void Parse(std::string filename);
  std::vector<s21::Matrix>& GetMatrix() { return parser->GetMatrix(); };
  std::vector<std::vector<size_t>>& GetPolygons() {
    return parser->GetPolygons();
  };
  size_t GetMatrix3DRows() { return parser->GetMatrix3DRows(); };

  // копирование и присваивание запрещены
  ViewerController(const ViewerController&) = delete;
  void operator=(const ViewerController&) = delete;
  s21::Matrix createTranslationMatrix(double x, double y, double z);
  s21::Matrix createScalingMatrix(double x, double y, double z);
  s21::Matrix createXRotationMatrix(double x);
  s21::Matrix createYRotationMatrix(double y);
  s21::Matrix createZRotationMatrix(double z);
  void moveModel(Parser* data, double x, double y, double z);
  void resizeModel(Parser* data, double x, double y, double z);
  void rotateModel(Parser* data, double x, double y, double z);
  s21::Parser& GetParser() { return *parser; };

 private:
  // Приватный конструктор
  ViewerController();
  s21::AffineTransform* affine_transform;
  s21::Parser* parser;
};
}  // namespace s21
