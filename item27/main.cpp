#include <iostream>

class B1
{
    int i;
};

class B2
{
    int i;
};

class D : public B1, public B2
{
    int i;
};

int
main()
{
    D aD;
    std::cout << &aD << std::endl;
    std::cout << static_cast<B1*>( &aD ) << std::endl;
    std::cout << static_cast<B2*>( &aD ) << std::endl;
    return 0;
}
