#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

void simple() {
  // From Wikipedia.

  std::unique_ptr<int> p1(new int(5));

  // Compile error - can't copy p1!
  // std::unique_ptr<int> p2 = p1;

  assert(p1 != NULL);
  // Transfers ownership. p3 now owns the memory and p1 is rendered invalid:
  std::unique_ptr<int> p3 = std::move(p1);
  assert(p1 == NULL && p3 != NULL);
}

void container() {
  std::vector<std::unique_ptr<int>> v;
  std::unique_ptr<int> q(new int(42));

  assert(q != NULL);
  // v.push_back(q); <- Compile error
  v.push_back(std::move(q));
  assert(q == NULL);

  for (auto &e : v) {
    std::cout << *e << std::endl;
  }
}

int main(void) {
  simple();
  container();
}
