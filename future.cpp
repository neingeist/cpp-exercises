// future example
// adapted from http://www.cplusplus.com/reference/future/future/

#include <cassert>
#include <chrono>         // std::chrono::milliseconds
#include <future>         // std::async, std::future
#include <iostream>

// a non-optimized way of checking for prime numbers.
bool is_prime(uint64_t x) {
  for (uint64_t i = 2; i < x; ++i) {
    if (x%i == 0) return false;
  }
  return true;
}

void explicitly_waiting() {
  uint64_t p = 817504243;

  // call function asynchronously:
  std::future<bool> fut = std::async(std::launch::async, is_prime, p);

  // do something while waiting for function to set future:
  std::cout << "checking, please wait" << std::flush;
  std::chrono::milliseconds span(500);
  while (fut.wait_for(span) == std::future_status::timeout) {
    std::cout << '.' << std::flush;
  }
  std::cout << std::endl;

  bool x = fut.get();     // retrieve return value
  std::cout << p << " " << (x?"is":"is not") << " prime." << std::endl;
  assert(x);
}

void implicitly_waiting() {
  uint64_t p2 = 685102597328182763;

  std::future<bool> fut = std::async(std::launch::async, is_prime, p2);
  std::cout << "just getting the result, doing an implicit wait():";
  std::cout << std::endl;
  bool x = fut.get();
  std::cout << p2 << " " << (x?"is":"is not") << " prime." << std::endl;
  assert(!x);
}

int main() {
  explicitly_waiting();
  implicitly_waiting();
  return 0;
}
