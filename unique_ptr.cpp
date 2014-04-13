#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

int main(void) {
  std::vector<std::unique_ptr<int>> v;
  std::unique_ptr<int> q(new int(42));

  assert(q != NULL);
  // v.push_back(q);
  v.push_back(std::move(q));
  assert(q == NULL);

  for(auto &e: v) {
    std::cout << *e << std::endl;
  }
}
