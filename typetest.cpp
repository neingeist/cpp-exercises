#include <cassert>
#include <iostream>

int main()
{
  int someInteger = 256;
  short someShort;
  long someLong;
  float someFloat;
  double someDouble;

  someInteger++;
  assert(someInteger == 257);

  someInteger *= 2;
  assert(someInteger == 514);

  someShort = (short) someInteger;
  assert((int) someShort == 514); // (short more than 1 byte)

  someLong = someShort * 10000;
  assert(someLong == 5140000l);

  someFloat = someLong * 0.785;
  assert(abs(someFloat - 4034900.000) < 0.0001);

  someDouble = (double)someFloat / 100000;
  assert(abs(someDouble - 40.349) < 0.0001);

  std::cout << someDouble << std::endl;

  return 0;
}
