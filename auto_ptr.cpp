#include <cassert>
#include <iostream>
#include <memory>

// auto_ptr<> is deprecated, i know.
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

int main() {
    int *i = new int;
    std::auto_ptr<int> x(i);
    std::auto_ptr<int> y;
    /* Note: auto_ptr is deprecated. */

    y = x;

    std::cout << x.get() << std::endl;  // Print NULL
    assert(x.get() == NULL);
    std::cout << y.get() << std::endl;  // Print non-NULL address i
    assert(y.get() != NULL);

    return 0;
}
