#include <iostream>
#include <string>

class mybase {
  protected:

    std::string ids;

  public:

    mybase(std::string ids)
      : ids(ids) {}

  virtual void foo() {
    std::cout << "i'm a mybase! ids: " << ids << std::endl;
  }
};

class myclass : public mybase {

  public:

  myclass(std::string ids)
    : mybase(ids) {}

  void foo() {
    std::cout << "i'm a myclass! ids: " << ids << std::endl;
  }

};

void nocast(myclass* x) {
  x->foo();
}

void ccast(void* x) {
  // C-style cast, guess that's not the C++ way, but works.
  myclass* foo = (myclass*) x;
  foo->foo();
}

void staticcast(void* x) {
  // C++ static_cast. When I *know* it's myclass*, and want to revert an implicit
  // conversion.
  myclass* foo = static_cast<myclass*>(x);
  foo->foo();
}

void dynamiccast(mybase* x) {
  // C++ dynamic_cast.
  if (myclass* foo = dynamic_cast<myclass*>(x)) {
    // only if x is actually a myclass*, this gets executed.
    foo->foo();
  }
}

int main() {
  myclass a("a");
  mybase base("base");

  std::cout << "== nocast" << std::endl;
  nocast(&a);
  // nocast(&base); <- Does not compile

  std::cout << "== ccast" << std::endl;
  ccast(&a);
  ccast(&base); // XXX actually works!

  std::cout << "== staticcast" << std::endl;
  staticcast(&a);
  staticcast(&base); // XXX actually works!

  std::cout << "== dynamiccast" << std::endl;
  dynamiccast(&a);
  dynamiccast(&base);
}
