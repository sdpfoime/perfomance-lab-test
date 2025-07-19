#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

void solution(std::string file1);
int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Problem with command line arguments\n";
    return -1;
  }
  std::string file1 = argv[1];
  solution(file1);
}

void solution(std::string file1) {
  std::vector<int> nums;
  int temp;

  std::ifstream array_in(file1);
  if (array_in.is_open()) {
    while (array_in >> temp) {
      nums.push_back(temp);
    }
  } else {
    std::cerr << "Problem with array file\n";
    return;
  }
  array_in.close();

  float diff = 0;
  for (auto num : nums) {
    diff += num;
  }
  diff = std::round(1.0f * diff / nums.size());

  int res = 0;
  for (auto num : nums) {
    res += std::abs(num - diff);
  }
  std::cout << res << "\n";
}
