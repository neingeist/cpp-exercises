#include <array>
#include <iostream>
#include <vector>

void classic() {
  int array[2];
  array[0] = 1;
  array[1] = 2;
  array[3] = 3; // <- clang++ -Warray-bounds warns about this

  int n = 10;
  std::cout << array[3] << std::endl; // no warning!
  std::cout << array[4] << std::endl; // no warning!
  std::cout << array[n-1] << std::endl; // no warning!
}

void std_array() {
  std::array<int, 2> array;
  array[0] = 1;
  array.at(1) = 2;

  // whoopsie
  array[2] = 3;

  for(auto &e: array) {
    std::cout << e << " ";
  }
  std::cout << std::endl;

  try {
    std::cout << array.at(2) << std::endl;
  } catch (std::out_of_range e) {
    std::cout << "cool, got std::out_of_range." << std::endl;
  }
}

void std_vector() {
  std::vector<int> vector(1);
  vector[0] = 1;
  try {
    vector.at(2) = 999;
  } catch (std::out_of_range e) {
    std::cout << "cool, got std::out_of_range." << std::endl;
  }
  vector.resize(10);
  vector.at(2) = 3;
  vector[1] = 2; // should now work
  // vector[3] = 3; // SEGFAULT

  for(auto &e: vector) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::cout << "== classic()" << std::endl;
  classic();

  std::cout << "== std_array()" << std::endl;
  std_array();

  std::cout << "== std_vector()" << std::endl;
  std_vector();

  return 0;
}
