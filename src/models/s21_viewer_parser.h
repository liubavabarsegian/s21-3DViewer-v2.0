//
// Created by Timofey on 17.02.2024.
//

#pragma once

#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "s21_matrix_oop.h"

namespace s21 {
class Parser {
 private:
  std::vector<std::array<double, 4>> matrix_3d;

  std::vector<std::vector<size_t>> polygons;

  std::vector<s21::Matrix> matrix;

  void scan_vertices(std::string &line);

  size_t line_num = 0;

  void scan_facets(std::string &line);

  bool IsAllDigits(std::string &str);

  void delete_space(std::string &line);

  void string_to_double_arr(std::array<double, 4> &arr, std::string &str,
                            size_t pos);

  void string_to_double_vector(std::vector<size_t> &vector, std::string &str);

  void ToMatrix();

  void loop_parser(std::ifstream &file);

  void CleanModel();

 public:
  void parser(std::string &filename);

  // void print_matrix_3d();

  // void print_polygons();

  // void print_s21_matrix(s21::Matrix matrix);

  size_t GetMatrix3DRows();

  size_t GetMatrix3DCols();

  // void print_matrix();

  s21::Matrix &GetPointMatrix(int rowNumber) { return matrix[rowNumber]; };

  std::vector<s21::Matrix> &GetMatrix() { return matrix; };

  void SetMatrix(int rowNumber, s21::Matrix &newMatrix) {
    this->GetPointMatrix(rowNumber) = newMatrix;
  };

  std::vector<std::vector<size_t>> &GetPolygons() { return polygons; };
};
}  // namespace s21
