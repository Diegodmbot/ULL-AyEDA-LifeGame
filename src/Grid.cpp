/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Algoritmo y Estructuras de Datos Avanzados
 * @file: P01DiegoDiazMoron/Grid
 * @author: Diego Diaz Moron
 * @mail: alu0101337975@ull.edu.es
 * @date: 22/02/22
 * @version: 0.1
 * @brief: El Juego de la Vida.
 */

#include "Grid.hpp"

Grid::Grid(char* arg) { Read(arg); }

Grid::~Grid() {}

int Grid::GetRowSize() { return row_size; }

int Grid::GetColumnSize() { return column_size; }

void Grid::NextGeneration(void) {}

void Grid::Write(void) {
  system("clear");
  std::cout << std::endl;
  std::cout << "|";
  for (int i = 0; i < column_size; i++) std::cout << "===";
  std::cout << "|" << std::endl;
  for (int i = 0; i < row_size; i++) {
    std::cout << "|";
    for (int j = 0; j < column_size; j++) {
      std::cout << ' ' << matrix_cell[i][j] << ' ';
    }
    std::cout << "|" << std::endl;
  }
  std::cout << "|";
  for (int i = 0; i < column_size; i++) std::cout << "===";
  std::cout << "|" << std::endl;
}

void Grid::Read(char* arg) {
  std::ifstream data_file;
  data_file.open(arg);
  if (!data_file.is_open()) {
    std::cout << "Ha ocurrido un error al abrir el fichero de lectura.";
    std::terminate();
  } else {
    std::string line;
    std::vector<std::string> file_lines;
    // Guarda en un string el fichero sin los comentarios
    while (std::getline(data_file, line)) {
      if (line.at(0) != '/') file_lines.push_back(line);
    }
    // Variable que indexa la línea del fichero que vamos a analizar
    int index = 0;
    // Tamano del mundo
    int rows, cols;
    std::stringstream ss_world(file_lines[index++]);
    ss_world >> rows >> cols;
    row_size = FormatSize(rows);
    column_size = FormatSize(cols);
    matrix_cell.resize(column_size);
    for (int i = 0; i < column_size; i++) matrix_cell[i].resize(column_size);
    // Numero de celulas
    int number_of_cells = std::stoi(file_lines[index++]);
    // Coordenadas de las celulas
    std::string srow, scol;
    for (int i = 0; i < number_of_cells; i++) {
      std::stringstream ss_cells(file_lines[index++]);
      ss_cells >> srow >> scol;
      int irow = std::stoi(srow);
      int icol = std::stoi(scol);
      if (BETWEEN(irow, 0, row_size) && BETWEEN(icol, 0, column_size))
        matrix_cell[irow][icol].SetActualState(kAlive);
    }
  }
  data_file.close();
}

int Grid::FormatSize(const int input) {
  return input <= 1 ? kDefaultSize : input;
}