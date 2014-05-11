/* http://en.wikipedia.org/wiki/C++14 */

#include <cassert>
#include <iostream>

auto sum(int i) {
  if (i == 1)
    return i;               // return type deduced as int
  else
    return sum (i-1) + i;   // ok to call it now
}

int main() {
  assert(sum(3) == 6);
  assert(sum(10) == 55);
}
