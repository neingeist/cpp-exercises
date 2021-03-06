#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

// From Wikipedia.

void shared_ptr() {
  std::cout << __FUNCTION__ << std::endl;

  std::shared_ptr<int> p1(new int(5));
  std::shared_ptr<int> p2 = p1;  // Both now own the memory.
  assert(p1.use_count() == 2);

  // Memory still exists, due to p2:
  p1.reset();
  assert(p1.get() == NULL && p2.get() != NULL);
  assert(p2.use_count() == 1);
  assert(p1.use_count() == 0);

  // Deletes the memory, since no one else owns the memory.
  p2.reset();
  assert(p1.get() == NULL && p2.get() == NULL);
  assert(p2.use_count() == 0);
  assert(p1.use_count() == 0);
}

void shared_ptr_container() {
  std::cout << __FUNCTION__ << std::endl;

  std::shared_ptr<int> p1(new int(5));
  std::shared_ptr<int> p2 = p1;  // Both now own the memory.
  assert(p1.use_count() == 2);

  std::vector<std::shared_ptr<int>> v;
  v.push_back(p1);
  v.push_back(p1);
  assert(p1.use_count() == 4);
  p2.reset();
  assert(p1.use_count() == 3);
  assert(p2.use_count() == 0);

  v.pop_back();
  v.pop_back();
  assert(p1.use_count() == 1);
}

void weak_ptr() {
  std::cout << __FUNCTION__ << std::endl;

  std::shared_ptr<int> p1(new int(5));
  std::weak_ptr<int> wp1 = p1;  // p1 owns the memory.

  {
    std::shared_ptr<int> p2 = wp1.lock();  // Now p1 and p2 own the memory.
    assert(p2 != NULL);
    if (p2) {  // As p2 is initialized from a weak pointer,
               // you have to check if the memory still exists!
      // Do something with p2
    }
  }  // p2 is destroyed. Memory is owned by p1.

  assert(wp1.lock() != NULL);
  assert(wp1.use_count() == 1);
  p1.reset();  // Memory is deleted.
  assert(wp1.lock() == NULL);
  assert(wp1.use_count() == 0);

  std::shared_ptr<int> p3 = wp1.lock();
  // Memory is gone, so we get an empty shared_ptr.
  assert(p3 == NULL);
  if (p3) {
    // Will not execute this.
  }
}

void add_one(std::shared_ptr<int> i) {
  (*i)++;
}

void make_shared() {
  std::cout << __FUNCTION__ << std::endl;

  std::shared_ptr<int> sp = std::shared_ptr<int>(new int(12));
  assert(*sp == 12);
  add_one(sp);
  assert(*sp == 13);

  auto sp2 = std::shared_ptr<int>(new int(12));
  assert(*sp2 == 12);
  add_one(sp2);
  add_one(sp2);
  add_one(sp2);
  assert(*sp2 == 15);

  auto sp3 = std::make_shared<int>(12);
  assert(*sp3 == 12);
  add_one(sp3);
  add_one(sp3);
  assert(*sp3 == 14);
}

int main() {
  shared_ptr();
  shared_ptr_container();
  weak_ptr();
  make_shared();
}
