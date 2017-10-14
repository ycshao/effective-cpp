#include <iostream>


template<unsigned n>
struct Factorial {
    enum { value = n * Factorial<n-1>::value };
};

template<>
struct Factorial<0> {
    enum { value = 1 };
};

int main() {

    std::cout << Factorial<0>::value << std::endl;
    std::cout << Factorial<1>::value << std::endl;
    std::cout << Factorial<2>::value << std::endl;
    std::cout << Factorial<3>::value << std::endl;
    std::cout << Factorial<4>::value << std::endl;
    return 0;
}

