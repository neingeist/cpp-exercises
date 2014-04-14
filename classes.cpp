#include <iostream>
#include <vector>

class Animal {
  public:
    // Note: using *virtual* does the difference here!
    virtual void makeSound() const {
      std::cout << "<generic animal sound> from " << this << std::endl;
    }

    Animal& operator= (Animal &a) {
      std::cout << "lol, operator= of " << this;
      std::cout << "(arg: " << &a << ")" << std::endl;

      return *this;
    }
};

class Cow : public Animal {
  public:
    void makeSound() const {
      std::cout << "Mooh. from " << this << std::endl;
    }
};

class Cat : public Animal {
  public:
    void makeSound() const {
      std::cout << "Meow? from " << this << std::endl;
    }
};

void call(Animal a) {
  a.makeSound();
}

void callref(Animal &a) {
  a.makeSound();
}

void callptr(Animal* a) {
  a->makeSound();
}

int main() {
  Cat cat;
  Cow cow;

  std::cout << "== Some animals" << std::endl;
  Animal animal;
  animal.makeSound();
  call(animal);
  callref(animal);
  callptr(&animal);

  animal = cat; // <- lol, operator
  animal.makeSound();
  call(cat);
  callref(cat); // <- meow
  callptr(&cat); // <- meow

  animal = cow; // <- lol, operator
  animal.makeSound();
  call(cow);
  callref(cow); // <- mooh
  callptr(&cow); // <- mooh

  std::cout << "== refs" << std::endl;
  Animal &aref = cat;
  aref.makeSound(); // <- meow
  aref = cow; // <- lol, operator
  aref.makeSound(); // <- meow, still

  std::cout << "== vector<Animal>:" << std::endl;
  // Does nothing:
  std::vector<Animal> animals = { cat, cow }; // <- Copies
  for (auto &a: animals) {
    a.makeSound();
  }

  std::cout << "== vector<Animal*>:" << std::endl;
  // Meow? Mooh.
  std::vector<Animal*> animalptrs = { &cat, &cow };
  for (auto &a: animalptrs) {
    a->makeSound();
  }
}
