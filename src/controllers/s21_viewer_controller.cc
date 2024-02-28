#include "s21_viewer_controller.h"

namespace s21 {

ViewerController::ViewerController() {
  parser = new Parser();
  affine_transform = new AffineTransform();
}

Matrix ViewerController::createTranslationMatrix(double x, double y, double z) {
  affine_transform->createTranslationMatrix(x, y, z);
}

Matrix ViewerController::createScalingMatrix(double x, double y, double z) {
  affine_transform->createScalingMatrix(x, y, z);
}

Matrix ViewerController::createXRotationMatrix(double x) {
  affine_transform->createXRotationMatrix(x);
}

Matrix ViewerController::createYRotationMatrix(double y) {
  affine_transform->createYRotationMatrix(y);
}

Matrix ViewerController::createZRotationMatrix(double z) {
  affine_transform->createZRotationMatrix(z);
}

void ViewerController::moveModel(Parser* data, double x, double y, double z) {
  affine_transform->moveModel(data, x, y, z);
}

void ViewerController::resizeModel(Parser* data, double x, double y, double z) {
  affine_transform->resizeModel(data, x, y, z);
}
void ViewerController::rotateModel(Parser* data, double x, double y, double z) {
  affine_transform->rotateModel(data, x, y, z);
}

void ViewerController::Parse(std::string filename) { parser->parser(filename); }
}  // namespace s21
