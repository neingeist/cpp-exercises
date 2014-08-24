#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
  char** foo = new char*[100];
  delete[] foo;

  char** bar = (char**) malloc(100*sizeof(char*));
  assert(bar != NULL);
  // for valgrind to find:
  // free(bar);
}
