#include <cassert>
#include <memory>

// From Wikipedia.

void shared_ptr() {
  std::shared_ptr<int> p1(new int(5));
  std::shared_ptr<int> p2 = p1; // Both now own the memory.

  // Memory still exists, due to p2:
  p1.reset();
  assert(p1.get() == NULL && p2.get() != NULL);

  // Deletes the memory, since no one else owns the memory.
  p2.reset();
  assert(p1.get() == NULL && p2.get() == NULL);
}

void weak_ptr() {
  std::shared_ptr<int> p1(new int(5));
  std::weak_ptr<int> wp1 = p1; // p1 owns the memory.

  {
    std::shared_ptr<int> p2 = wp1.lock(); //Now p1 and p2 own the memory.
    assert(p2 != NULL);
    if (p2) { // As p2 is initialized from a weak pointer,
              // you have to check if the memory still exists!
      // Do something with p2
    }
  } // p2 is destroyed. Memory is owned by p1.

  assert(wp1.lock() != NULL);
  p1.reset(); // Memory is deleted.
  assert(wp1.lock() == NULL);

  std::shared_ptr<int> p3 = wp1.lock();
  // Memory is gone, so we get an empty shared_ptr.
  assert(p3 == NULL);
  if (p3) {
    // Will not execute this.
  }
}

int main() {
  shared_ptr();
  weak_ptr();
}
