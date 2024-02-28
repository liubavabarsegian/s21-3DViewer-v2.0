#include "s21_matrix_oop.h"

/* Сonstructor overloads */
s21::Matrix::Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

s21::Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ < 0 || cols_ < 0) {
    throw std::length_error("The matrix's dimension can't be neg");
  }

  matrix_ = new double[rows_ * cols_]();
}

s21::Matrix::Matrix(const Matrix &other)
    : rows_(other.rows_),
      cols_(other.cols_),
      matrix_(new double[rows_ * cols_]()) {
  std::copy(other.matrix_, other.matrix_ + rows_ * cols_, matrix_);
}

s21::Matrix::Matrix(Matrix &&other) noexcept {
  rows_ = std::exchange(other.rows_, 0);
  cols_ = std::exchange(other.cols_, 0);
  matrix_ = std::exchange(other.matrix_, nullptr);
}

/* Destructor */
s21::Matrix::~Matrix() {
  delete[] matrix_;
  matrix_ = nullptr;
}

/* Helper methods */
void s21::Matrix::setRows(const int &new_rows) {
  if (new_rows < 0) {
    throw std::length_error("Array's size can't be neg");
  }

  Matrix tmp(new_rows, cols_);
  for (int i = 0; i < (rows_ < new_rows ? rows_ : new_rows); ++i) {
    for (int j = 0; j < cols_; ++j) {
      tmp[i][j] = (*this)[i][j];
    }
  }

  *this = std::move(tmp);
}

void s21::Matrix::setCols(const int &new_cols) {
  if (new_cols < 0) {
    throw std::length_error("Array's size can't be neg");
  }

  Matrix tmp(rows_, new_cols);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < (cols_ < new_cols ? cols_ : new_cols); ++j) {
      tmp[i][j] = (*this)[i][j];
    }
  }

  *this = std::move(tmp);
}

int s21::Matrix::getRows() const noexcept { return rows_; }

int s21::Matrix::getCols() const noexcept { return cols_; }

/* Operator overloading */
double &s21::Matrix::operator()(int row, int col) const {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw std::out_of_range("The entered index is incorrect");
  }

  return matrix_[row * cols_ + col];
}

double *s21::Matrix::operator[](int row) const {
  if (row >= rows_) {
    throw std::out_of_range("The entered index is incorrect");
  }

  return row * cols_ + matrix_;
}

s21::Matrix &s21::Matrix::operator=(Matrix &&other) noexcept {
  if (this != &other) {
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
  }

  return *this;
}

s21::Matrix &s21::Matrix::operator=(const Matrix &other) {
  if (this != &other) {
    delete[] matrix_;

    rows_ = other.rows_;
    cols_ = other.cols_;

    matrix_ = new double[rows_ * cols_]();
    std::copy(other.matrix_, other.matrix_ + rows_ * cols_, matrix_);
  }
  return *this;
}

bool s21::Matrix::operator==(const Matrix &other) const noexcept {
  return EqMatrix(other);
}

bool s21::Matrix::EqMatrix(const Matrix &other) const noexcept {
  if (rows_ != other.getRows() || cols_ != other.getCols()) {
    return false;
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (std::fabs((*this)[i][j] - other[i][j]) > ACCURACY) {
        return false;
      }
    }
  }

  return true;
}

s21::Matrix &s21::Matrix::operator+=(const Matrix &other) {
  SumMatrix(other);
  return *this;
}

s21::Matrix s21::Matrix::operator+(const Matrix &other) const {
  Matrix res{*this};
  return res += other;
}

s21::Matrix &s21::Matrix::operator-=(const Matrix &other) {
  SubMatrix(other);
  return *this;
}

s21::Matrix s21::Matrix::operator-(const Matrix &other) const {
  Matrix res{*this};
  res.SubMatrix(other);

  return res;
}

s21::Matrix &s21::Matrix::operator*=(const Matrix &other) {
  MulMatrix(other);
  return *this;
}

s21::Matrix &s21::Matrix::operator*=(const double &value) {
  MulNumber(value);
  return *this;
}

s21::Matrix s21::Matrix::operator*(const Matrix &other) const {
  Matrix res{*this};
  res.MulMatrix(other);

  return res;
}

/* Main methods */
void s21::Matrix::SumMatrix(const Matrix &other) {
  if (rows_ != other.getRows() || cols_ != other.getCols()) {
    throw std::logic_error("Error in the dimension combination for sum");
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      (*this)[i][j] += other[i][j];
    }
  }
}

void s21::Matrix::SubMatrix(const Matrix &other) {
  if (rows_ != other.getRows() || cols_ != other.getCols()) {
    throw std::logic_error("Error in the dimension combination for sub");
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      (*this)[i][j] -= other[i][j];
    }
  }
}

void s21::Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      (*this)[i][j] *= num;
    }
  }
}

void s21::Matrix::MulMatrix(const Matrix &other) {
  if (cols_ != other.getRows()) {
    throw std::logic_error("Error in the dimension combination for mul");
  }

  Matrix res(this->rows_, other.getCols());

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.getCols(); ++j) {
      for (int k = 0; k < cols_; k++) {
        res[i][j] += (*this)[i][k] * other[k][j];
      }
    }
  }

  *this = std::move(res);
}
