#include <cstdio>

struct A {
  A() { puts("A()"); }
  ~A() { puts("~A()"); }
};

struct B {
  B() { puts("B()"); }
  ~B() { puts("~B()"); }
};

struct C {
  A a;
  B b;

  C()
  : a(), b() {
    puts("C()");
  }
  ~C() { puts("~C()"); }
};

int main() {
  C c;
  // Destructors should be called in exactly the opposite order of the
  // constructor calls.
}
