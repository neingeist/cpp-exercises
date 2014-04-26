#include <iostream>
#include <stdexcept>
#include <typeinfo>


class Nail {
  public:
    Nail(float length)
    : length(length) {};

    float getLength() {
      return length;
    }

  private:
    float length;
};


class Tool {
  public:
    virtual void use() {
      std::cout << "Just using some tool." << std::endl;
    }
};


class Hammer : public Tool {
  public:
    virtual void use() {
      std::cout << "Hammer time!" << std::endl;
    }

    void use(Nail nail) {
      std::cout << "The nail is " << nail.getLength() << " cm long" << std::endl;
    }
};


class SledgeHammer : public Hammer {
  public:
    void use(Nail nail __attribute__((unused))) {
      throw std::runtime_error("Can't use a sledge hammer on nails!");
    }
};


void useSomeTool(Tool &tool) {
  // RTTI gives up the type of the derived class.
  std::cout << "Look, it's a " << typeid(tool).name() << "!" << std::endl;

  // XXX What about subclasses of Hammer?
  if(typeid(tool) == typeid(Hammer)) {
    std::cout << "Stop! ";
  }
  tool.use();

  // Or dynamic_cast it and use it on a nail
  // XXX How to use a reference here?
  Hammer* h = dynamic_cast<Hammer*>(&tool);
  if (h) {
    Nail nail(10);
    h->use(nail);
  }
}


int main() {
  Tool tool;
  Hammer hammer;
  SledgeHammer sledgehammer;

  useSomeTool(tool);
  useSomeTool(hammer);
  useSomeTool(sledgehammer);
}

// XXX http://en.cppreference.com/w/cpp/language/typeid
// XXX https://en.wikipedia.org/wiki/Dynamic_cast
