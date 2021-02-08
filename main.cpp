#include <iostream>
#include "BoolVector.h"

int main() {
    BoolVector bv1("1000101");
    BoolVector bv2("11111111010101");
    bv1 ^= bv2;
    std::cout << bv1 << std::endl;
    bv1.inversion();
    std::cout << bv1 << std::endl;
    std::cout << bv1[0] << std::endl;
    return 0;
}
