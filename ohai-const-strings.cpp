// how to convert std::vector<std::string> to const char**?

#include <string.h>

#include <iostream>
#include <string>
#include <vector>

void print_strings(const std::vector<std::string> strings) {
  using std::cout;
  using std::endl;

  cout << "== Printing some std::vector<std::string> strings:" << endl;
  for (const std::string &s : strings) {
    cout << s << endl;
  }
}

const char** convert_to_c(const std::vector<std::string> strings) {
  // Note: perfectly fine to "new" const char*.
  const char** strings_c = new const char*[strings.size()+1];
  for (size_t i = 0; i < strings.size(); ++i) {
    // Note: const char** = non-const "array" to const char*, i.e. can modify
    //       pointers to the strings but not the strings themselves.
    strings_c[i] = strings.at(i).c_str();
  }
  strings_c[strings.size()] = NULL;

  return strings_c;
}

void free_c(const char** strings_c) {
  delete[] strings_c;
}

void print_strings_c(const char** strings_c) {
  using std::cout;
  using std::endl;

  cout << "== Printing some const char** strings:" << endl;
  for (size_t i = 0; strings_c[i] != NULL; ++i) {
    cout << strings_c[i] << endl;
  }
}

void foo(const char* string) {
  printf("foo: %s\n", string);
}

int main() {
  foo("foo");
  char* bar = new char[4];
  strncpy(bar, "bar", 4);
  foo(bar);
  delete[] bar;

  std::vector<std::string> some_strings = { "just", "some", "strings", "here" };
  print_strings(some_strings);

  const char **some_strings_c = convert_to_c(some_strings);

  print_strings_c(some_strings_c);
  free_c(some_strings_c);
}
