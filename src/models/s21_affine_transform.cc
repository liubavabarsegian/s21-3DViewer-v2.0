#include "s21_affine_transform.h"

namespace s21 {

AffineTransform::AffineTransform() {}

AffineTransform::~AffineTransform() {}

Matrix AffineTransform::createTranslationMatrix(double x, double y, double z) {
  Matrix result(4, 4);
  for (int i = 0; i < 4; i++) {
    result[i][i] = 1;
  }

  result[3][0] = x;
  result[3][1] = y;
  result[3][2] = z;
  return result;
}

Matrix AffineTransform::createScalingMatrix(double x, double y, double z) {
  Matrix result(4, 4);
  result[0][0] = x;
  result[1][1] = y;
  result[2][2] = z;
  result[3][3] = 1;
  return result;
}

Matrix AffineTransform::createXRotationMatrix(double x) {
  Matrix result(4, 4);
  x = (x * PI) / 180;
  result[0][0] = 1;
  result[1][1] = cos(x);
  result[1][2] = sin(x);
  result[2][2] = cos(x);
  result[2][1] = -1 * sin(x);
  result[3][3] = 1;
  return result;
}

Matrix AffineTransform::createYRotationMatrix(double y) {
  Matrix result(4, 4);
  y = (y * PI) / 180;
  result[0][0] = cos(y);
  result[1][1] = 1;
  result[0][2] = -1 * sin(y);
  result[2][2] = cos(y);
  result[2][0] = sin(y);
  result[3][3] = 1;
  return result;
}

Matrix AffineTransform::createZRotationMatrix(double z) {
  Matrix result(4, 4);
  z = (z * PI) / 180;
  result[0][0] = cos(z);
  result[1][1] = cos(z);
  result[0][1] = sin(z);
  result[2][2] = 1;
  result[1][0] = -1 * sin(z);
  result[3][3] = 1;
  return result;
}

void AffineTransform::moveModel(Parser* data, double x, double y, double z) {
  Matrix translate = createTranslationMatrix(x, y, z);
  Matrix current(1, 4);

  for (int i = 0; i < (int)data->GetMatrix3DRows(); ++i) {
    current = data->GetPointMatrix(i);
    current[0][3] = 1;
    current *= translate;
    data->SetMatrix(i, current);
  }
}

void AffineTransform::resizeModel(Parser* data, double x, double y, double z) {
  Matrix scale = createScalingMatrix(x, y, z);
  Matrix current(1, 4);

  for (int i = 0; i < (int)data->GetMatrix3DRows(); ++i) {
    current = data->GetPointMatrix(i);
    current *= scale;
    data->SetMatrix(i, current);
  }
}

void AffineTransform::rotateModel(Parser* data, double x, double y, double z) {
  Matrix rotate(4, 4);
  Matrix current(1, 4);
  if (x != 0) {
    rotate = createXRotationMatrix(x);
  } else if (y != 0) {
    rotate = createYRotationMatrix(y);
  } else if (z != 0) {
    rotate = createZRotationMatrix(z);
  }

  for (int i = 0; i < (int)data->GetMatrix3DRows(); ++i) {
    current = data->GetPointMatrix(i);
    current *= rotate;
    data->SetMatrix(i, current);
  }
}

}  // namespace s21
