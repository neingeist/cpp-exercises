// http://www.cplusplus.com/reference/numeric/accumulate/

#include <cassert>
#include <iostream>

#include <functional>   // std::minus
#include <numeric>      // std::accumulate

int myfunction (int x, int y) { return x+2*y; }

struct myclass {
  int operator()(int x, int y) const { return x+3*y; }
} myobject;

int main() {
  int init = 100;
  int numbers[] = {10,20,30};
  int res;

  std::cout << "using default accumulate: ";
  res = std::accumulate(numbers, numbers+3, init);
  std::cout << res;
  assert(res == 100+10+20+30);
  std::cout << '\n';

  std::cout << "using functional's minus: ";
  res = std::accumulate(numbers, numbers+3, init, std::minus<int>());
  std::cout << res;
  assert(res == 100-10-20-30);
  std::cout << '\n';

  std::cout << "using custom function: ";
  res = std::accumulate(numbers, numbers+3, init, myfunction);
  std::cout << res;
  assert(res == 100+20+40+60);
  std::cout << '\n';

  std::cout << "using custom object: ";
  res = std::accumulate(numbers, numbers+3, init, myobject);
  std::cout << res;
  assert(res == 100+30+60+90);
  std::cout << '\n';

  return 0;
}
