#include <iostream>
#include <random>

int main() {

  // Generate random numbers
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(1, 10);

  int secret_num = dist(gen);

  std::cout << secret_num << std::endl;

  return 0;
}
