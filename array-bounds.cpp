#include <array>
#include <iostream>
#include <vector>

void classic() {
  int array[2];
  array[0] = 1;
  array[1] = 2;
  // array[3] = 3; <- clang++ -Warray-bounds warns about this
  // array[4] = 4; <- clang++ -Warray-bounds warns about this

  int n = 10;
  std::cout << array[3] << std::endl; // no warning!
  std::cout << array[4] << std::endl; // no warning!
  std::cout << array[n-1] << std::endl; // no warning!
}

// FIXME
void std_array() {
  std::array<int, 2> array;
  array[0] = 1;
  array[1] = 2;
  array[3] = 3; // XXX <- clang++ -Warray-bounds warns about this
  // array[4] = 4; <- clang++ -Warray-bounds warns about this

  int n = 10;
  std::cout << array[3] << std::endl; // no warning!
  std::cout << array[4] << std::endl; // no warning!
  std::cout << array[n-1] << std::endl; // no warning!
}

// FIXME
void std_vector() {
  std::vector<int> vector;
  vector[0] = 1;
  vector[1] = 2;
  // vector[3] = 3; // SEGFAULT
  // vector[4] = 4; <- clang++ -Warray-bounds warns about this

  int n = 10;
  // std::cout << vector[3] << std::endl; // no warning!
  // std::cout << vector[4] << std::endl; // no warning!
  // std::cout << vector[n-1] << std::endl; // no warning!
}

int main() {
  std::cout << "classic()" << std::endl;
  classic();

  std::cout << "std_array()" << std::endl;
  std_array();

  std::cout << "std_vector()" << std::endl;
  std_vector();

  return 0;
}
