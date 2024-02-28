#include "s21_viewer_parser.h"

// ========== example ================
// int main(void) {
//    s21::Parser model;
//    try {
//         std::string file =
//         "/Users/timofey/SCHOOL21_PROJECTS/CPP4_3DViewer_v2.0-1/src/objs/cat.obj";
////        std::string file =
///"/Users/timofey/Desktop/CPP4_3DViewer_v2.0-1/src/test_obj.obj"; / std::string
//  file = "../../src/objs/cat.obj";
//        //    std::string file = "../objs/cube.obj";
//
//        model.parser(file);
////         std::cout << model.GetMatrix3DRows() << std::endl;
////         std::cout << model.GetMatrix3DCols() << std::endl;
////         model.print_matrix_3d();
//         model.print_matrix();
////        model.print_polygons();
////         std::cout << model.GetMatrix3DRows();
////         std::cout << std::endl;
////         model.print_matrix();
////         std::vector<std::ve/ctor<size_t>> pol = model.GetPolygons();
////         std::cout << pol[0][0];
//        //        print_matrix();
//    } catch (const std::exception &e) {
//        std::cout << e.what();
//    }
//
//
//    return 0;
//}

size_t s21::Parser::GetMatrix3DRows() { return this->matrix_3d.size(); }

size_t s21::Parser::GetMatrix3DCols() { return this->matrix_3d[0].size(); }

void s21::Parser::ToMatrix() {
  matrix.resize(static_cast<int>(GetMatrix3DRows()));
  int n = static_cast<int>(GetMatrix3DRows());
  int m = static_cast<int>(GetMatrix3DCols());

  for (int i = 0; i < n; ++i) {
    matrix[i] = s21::Matrix(1, 4);

    for (int j = 0; j < m; ++j) {
      s21::Matrix tmp_matrix = matrix[i];
      matrix[i](0, j) = matrix_3d[i][j];
      //            matrix[i][0][j] = matrix_3d[i][j];
    }
  }
}

void s21::Parser::parser(std::string& filename) {
  CleanModel();
  std::ifstream file(filename);
  if (file.is_open()) {
    loop_parser(file);
  }
  if (!file.eof() && file.fail()) {
    throw std::invalid_argument("error reading!!!");
  }
  file.close();
  ToMatrix();
}

void s21::Parser::loop_parser(std::ifstream& file) {
  char letter;
  while (file.good()) {
    ++line_num;
    std::string line;
    file.get(letter);
    if (letter == 'v') {
      std::getline(file, line);
      if (line[0] != ' ') {
        continue;
      }
      //            scan_vertices(file, line);
      scan_vertices(line);
    } else if (letter == 'f') {
      std::getline(file, line);
      if (line[0] != ' ') {
        continue;
      }
      //            scan_facets(file, line);
      scan_facets(line);
    } else if (letter != '\n') {
      std::getline(file, line);
    }
  }
}
//
// void s21::Parser::print_matrix_3d() {
//    for (int i = 0; i < (int)matrix_3d.size(); ++i) {
//        std::cout << i + 1 << "  ";
//        for (int j = 0; j < 4; ++j) {
//            std::cout << matrix_3d[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//}

// void s21::Parser::scan_vertices(std::ifstream& file, std::string& line) {
void s21::Parser::scan_vertices(std::string& line) {
  delete_space(line);
  std::string token;
  std::array<double, 4> temp_arr{};
  int i = 0;
  size_t pos = line.find(' ');
  while (pos != std::string::npos) {
    token = line.substr(0, pos);
    string_to_double_arr(temp_arr, token, i);
    ++i;
    line.erase(0, pos + 1);
    if (!line.empty()) {
      delete_space(line);
    }
    pos = line.find(' ');
  }
  if (!line.empty()) {
    string_to_double_arr(temp_arr, line, i);
  }
  //    if (i != 2) {
  //        throw std::invalid_argument("должно быть 3 координаты");
  //    }
  matrix_3d.push_back(temp_arr);
}

void s21::Parser::string_to_double_arr(std::array<double, 4>& arr,
                                       std::string& str, size_t pos) {
  try {
    arr[pos] = std::stod(str);
  } catch (const std::exception& error) {
    throw std::invalid_argument(
        "stod: no conversion\nнайдено не число, ошибка в файле");
  }
}

void s21::Parser::delete_space(std::string& line) {
  size_t first_digit = 0;
  for (; first_digit < line.size(); ++first_digit) {
    if (line[first_digit] != ' ') {
      break;
    }
  }
  line.erase(0, first_digit);
  //    if (line.empty()) {
  //        throw std::invalid_argument("некорректный файл");
  //    }
}

// void s21::Parser::scan_facets(std::ifstream& file, std::string& line) {
void s21::Parser::scan_facets(std::string& line) {
  delete_space(line);
  size_t pos = 0;
  std::string token;
  std::vector<size_t> tmp_v;
  int i = 0;
  while ((pos = line.find(' ')) != std::string::npos) {
    token = line.substr(0, pos);
    size_t slash_pos = token.find('/');
    if (slash_pos != std::string::npos) {
      token.erase(slash_pos, token.size());
    }
    string_to_double_vector(tmp_v, token);
    ++i;
    line.erase(0, pos + 1);
    if (!line.empty()) {
      delete_space(line);
    }
  }
  size_t slash_pos = line.find('/');
  if (slash_pos != std::string::npos) {
    line.erase(slash_pos, line.size());
    string_to_double_vector(tmp_v, line);
  }
  if (!line.empty() && IsAllDigits(line)) {
    string_to_double_vector(tmp_v, line);
  }
  polygons.push_back(tmp_v);
}

bool s21::Parser::IsAllDigits(std::string& str) {
  for (char letter : str) {
    if (!isdigit(letter)) {
      return false;
    }
  }
  return true;
}

void s21::Parser::string_to_double_vector(std::vector<size_t>& vector,
                                          std::string& str) {
  try {
    vector.push_back(std::stod(str) - 1);
  } catch (const std::exception& error) {
    throw std::invalid_argument(
        "stod: no conversion\nнайдено не число, ошибка в файле");
  }
}

// void s21::Parser::print_polygons() {
//     for (size_t i = 0; i < this->polygons.size(); ++i) {
//         std::cout << i + 1 << "    ";
//         for (size_t j = 0; j < this->polygons[i].size(); ++j) {
//             std::cout << this->polygons[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
// }

// void s21::Parser::print_s21_matrix(s21::Matrix matrix) {
//     for (int i = 0; i < matrix.getRows(); ++i){
//         for (int j = 0; j < matrix.getCols(); ++j){
//             std::cout << matrix(i, j) << " ";
//         }
//     }
// }
//
// void s21::Parser::print_matrix() {
////    std::vector<s21::Matrix> matrix;
////    for (int i = 0; i < (int)matrix.size(); ++i) {
//    for (size_t i = 0; i < this->matrix.size(); ++i) {
//        std::cout << i + 1 << "    ";
//        print_s21_matrix(matrix[i]);
//        std::cout << std::endl;
////        for (int j = 0; j < matrix[i].getCols(); ++j) {
////            std::cout << matrix[i][0][j] << " ";
////        }
////        std::cout << std::endl;
//    }
//
//}

void s21::Parser::CleanModel() {
  matrix.clear();
  matrix_3d.clear();
  polygons.clear();
}
