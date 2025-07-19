#include <iostream>
#include <string>
#include <vector>

void solution(int n, int m);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Problem with command line arguments\n";
    return -1;
  }

  int n = std::stoi(argv[1]), m = std::stoi(argv[2]);

  // Буду считать, что круговой массив длины 0 не может существовать, поэтому
  // верну ошибку
  if (n < 1) {
    std::cerr << "Problem with array size\n";
    return -1;
  }
  solution(n, m);
}

void solution(int n, int m) {

  // В задании не обговорено насчет массива длины 0, поэтому я буду
  // считать, что мы не можем сдвинуться, выводим 1 и завершаемся
  if (m == 0) {
    std::cout << 1 << "\n";
    return;
  }

  std::vector<int> vec;

  for (int i = 0; i < n; i++) {
    vec.push_back(i + 1);
  }

  int ind = 0;
  do {
    std::cout << vec[ind] << " ";
    ind = abs(ind + m - 1) % n;
  } while (ind != 0);

  std::cout << "\n";
}
