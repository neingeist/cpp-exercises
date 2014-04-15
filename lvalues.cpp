#include <cassert>

int test = 12;

int fnord_(const int i) {
  test += i;
  return test;
}

int& fnord(const int i) {
  test += i;
  return test;
}

int main() {
  test = 13;

  fnord_(5);
  assert(test == 18);

  // LOLNOPE:
  // fnord_(5)++;

  test = 13;

  fnord(5);
  assert(test == 18);

  fnord(5)++;
  assert(test == 24);
}
