#include <cassert>
#include <iostream>

int main() {
  assert(0/2 == 0);
  assert(1/2 == 0);
  assert(2/2 == 1);
  assert(3/2 == 1);
  assert(4/2 == 2);
  assert(5/2 == 2);

  assert(0.0/2 == 0);
  assert(1.0/2 == 0.5);
  assert(2.0/2 == 1);
  assert(2.0/2 == 1.0);

  std::cout << "divided we stand." << std::endl;
}
