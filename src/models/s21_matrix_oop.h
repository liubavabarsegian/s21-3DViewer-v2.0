#pragma once

#define ACCURACY 1e-6

#include <algorithm>
#include <cmath>
#include <iostream>

namespace s21 {
class Matrix {
 private:
  /* Private attributes */
  int rows_, cols_;
  double *matrix_;

 public:
  /* Constructors and destructor */
  Matrix();

  Matrix(int rows, int cols);

  Matrix(const Matrix &other);

  Matrix(Matrix &&other) noexcept;

  ~Matrix();

  /* Helper methods */
  int getRows() const noexcept;

  int getCols() const noexcept;

  void setRows(const int &new_rows);

  void setCols(const int &new_cols);

  /* Main methods */
  bool EqMatrix(const Matrix &other) const noexcept;

  void SumMatrix(const Matrix &other);

  void SubMatrix(const Matrix &other);

  void MulNumber(const double num);

  void MulMatrix(const Matrix &other);

  /* Operator overloading */
  double *operator[](int row) const;

  double &operator()(int row, int col) const;

  Matrix &operator+=(const Matrix &other);

  Matrix operator+(const Matrix &other) const;

  Matrix &operator-=(const Matrix &other);

  Matrix operator-(const Matrix &other) const;

  Matrix &operator*=(const Matrix &other);

  Matrix &operator*=(const double &value);

  Matrix operator*(const Matrix &other) const;

  Matrix operator*(const double &value) const;

  bool operator==(const Matrix &other) const noexcept;

  Matrix &operator=(Matrix &&other) noexcept;

  Matrix &operator=(const Matrix &other);
};
}  // namespace s21
