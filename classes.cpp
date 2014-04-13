#include <iostream>
#include <vector>

class Animal {
  public:
    // Note: using *virtual* does the difference here!
    virtual void makeSound() {
      std::cout << "<generic animal sound>" << std::endl;
    }
};

class Cow : public Animal {
  public:
    void makeSound() {
      std::cout << "Mooh." << std::endl;
    }
};

class Cat : public Animal {
  public:
    void makeSound() {
      std::cout << "Meow?" << std::endl;
    }
};

int main() {
  Cat cat;
  Cow cow;

  // Does nothing:
  std::vector<Animal> animals = { cat, cow };
  for (auto &a: animals) {
    a.makeSound();
  }

  // Meow? Mooh.
  std::vector<Animal*> animalptrs = { &cat, &cow };
  for (auto &a: animalptrs) {
    a->makeSound();
  }
}
