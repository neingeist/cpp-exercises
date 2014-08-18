// https://www.cs.uaf.edu/2010/spring/cs202/lecture/03_02_exceptions.html

#include <iostream>

using namespace std;

void dr_evil(int counter) {
  int *array = new int[100000000000/(1+10*counter)];
  cout << "Bwah ha ha!" << endl;
  delete[] array;
}

int foo(void) {
  for (int counter = 0; counter < 20; counter++) {
    try {
      cout << "About to call dr_evil with counter == " << counter << endl;
      dr_evil(counter);

      cout << "I guess he's not so evil!" << endl;
      break;
    } catch (std::bad_alloc &e) {
      cout << "Caught an exception: " << e.what() << endl;
    }
  }
  return 0;
}

int main(void) {
  foo();
}
