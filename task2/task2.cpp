#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

void solution(std::string file1, std::string file2);

int main(int argc, char *argv[]) {
  std::string file1;
  std::string file2;
  // В 1 задании было сказано, что параметры передаются в качестве аргументов
  // командной строки, но во 2 задании опущено словосочетание "командной
  // строки", поэтому программа будет смотреть, были ли переданы пути в argv,
  // иначе запросит ввод изнутри программы.

  if (argc == 3) {
    file1 = argv[1];
    file2 = argv[2];
  } else {
    std::cin >> file1;
    std::cin >> file2;
  }

  solution(file1, file2);
}

void solution(std::string file1, std::string file2) {
  float circle_radius = 0, circle_x = 0, circle_y = 0;
  std::vector<std::pair<float, float>> dots;

  std::ifstream circle_in(file1);
  if (circle_in.is_open()) {
    circle_in >> circle_x >> circle_y >> circle_radius;
  } else {
    std::cerr << "Problem with circle file\n";
    return;
  }
  circle_in.close();

  std::ifstream dots_in(file2);
  if (dots_in.is_open()) {
    float x, y;
    while (dots_in >> x >> y) {
      dots.push_back(std::pair(x, y));
    }
  } else {
    std::cerr << "Problem with dots file\n";
    return;
  }
  dots_in.close();

  float temp_radius = 0;
  float eps = 0.0001;
  for (auto dot : dots) {
    temp_radius = std::sqrt(std::pow(circle_x - dot.first, 2) +
                            std::pow(circle_y - dot.second, 2));

    if (std::abs(temp_radius - circle_radius) < eps) {
      std::cout << 0 << "\n";
    } else {
      if (temp_radius > circle_radius) {
        std::cout << 2 << "\n";
      } else {
        std::cout << 1 << "\n";
      }
    }
  }
}
