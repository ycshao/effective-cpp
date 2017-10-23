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
