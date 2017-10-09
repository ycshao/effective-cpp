#include "Widget.h"
#include "NastyWidget.h"
#include "RandomType.h"

void doProcessing(Widget& w) {
    if (w.size() > 5) {
        w.normalize();
        w.swap(w);
    }
}

// Uncomment this will yield compilation error:
// invalid operands to binary expression ('RandomType' and 'int')
// in the line of w.size() > 5
//void doProcessing(RandomType& w) {
//
//    if (w.size() > 5) {
//        w.normalize();
//        w.swap(w);
//    }
//}

template<typename T>
void doProcessingTP(T& w)
{
    if (w.size() > 5) {
        w.normalize();
        w.swap(w);
    }
}

bool operator>(RandomType, int)
{
    std::cout << "operator>(RandomType, int)\n";
    return true;
}


int main() {
    {
        Widget w;
        doProcessing(w);
    }
    std::cout << "-------------\n";
    {
        NastyWidget nw;
        doProcessing(nw);
    }
    std::cout << "-------------\n";
    {
        RandomType rd;
        doProcessingTP(rd);
    }
    return 0;
}

// Because w is declared to be of type Widget, w must support the Widget interface.
// We can look up this interface in the source code (e.g., the .h file for Widget)
// to see exactly what it looks like, so I call this an explicit interface —
// one explicitly visible in the source code.

// Because some of Widget's member functions are virtual,
// w's calls to those functions will exhibit runtime polymorphism:
// the specific function to call will be determined at runtime based on w's
// dynamic type

// Implicit interfaces are simply made up of a set of valid expressions.
// The expressions themselves may look complicated, but the constraints they
// impose are generally straightforward.
// The implicit interfaces exist only in developer's head.

// * Both classes and templates support interfaces and polymorphism.
// * For classes, interfaces are explicit and centered on function signatures.
//   Polymorphism occurs at runtime through virtual functions.
// * For template parameters, interfaces are implicit and based on valid expressions.
//   Polymorphism occurs during compilation through template instantiation and function overloading resolution.