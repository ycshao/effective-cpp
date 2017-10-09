#include <iostream>

static int x = 2;

template<typename T>
struct WildClass
{
    static int const_iterator;
    class Base{};
};

template <>
int WildClass<int>::const_iterator = 10;

template<typename C>
void print2nd(const C& container)
{
    std::cout << C::const_iterator * x << std::endl; // surprise, it's 10 * 2 = 20!
}

int main() {
    WildClass<int> container;
    print2nd(container);
    return 0;
}
// -------------------
// typename exceptions
// -------------------
template<typename T>
// base class list: typename not allowed
class Derived: public WildClass<T>::Base {
public:
    explicit Derived(int x)
    // typename is not allowed in a member init list
            : WildClass<T>::Base()
    {
        typename WildClass<T>::Base temp;
    }
};