#include <iostream>
#include <string>

/* abstract */
class Animal {
  public:
    // virtual std::string talk() = 0; /* pure virtual */
    virtual std::string talk() { ; /* or an implementation */
      return "<sound>";
    }
};

class Cat : public Animal {
  std::string talk() {
    return "Meow!";
  }
};

class Dog : public Animal {
  std::string talk() {
    return "Woof!";
  }
};

/* Note: need pointer or ref here! */
void letsHear(Animal& a) {
  std::cout << a.talk() << std::endl;
}

int main() {
  Cat c;
  Dog d;
  letsHear(c);
  letsHear(d);

  return 0;
}
