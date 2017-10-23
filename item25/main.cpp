#include <iostream>
#include <vector>

//////////////// template version
namespace WidgetStuff {
    template<typename T>
    class WidgetImplTP {
    private:
        std::vector<T> v;
    };

    template<typename T>
    class WidgetTP {
    public:
        WidgetTP &operator=(const WidgetTP &rhs) {
            *pImpl = *(rhs.pImpl);
            return *this;
        }

        void swap(WidgetTP &other) {
            std::cout << "WidgetTP::swap\n";
            using std::swap;
            swap(pImpl, other.pImpl);
        }

    private:
        WidgetImplTP<T> *pImpl;
    };

    template<typename T>
    void swap(WidgetTP<T> &a, WidgetTP<T> &b) {
        std::cout << "WidgetTP::swap(WidgetTP<T>& a, WidgetTP<T>& b)\n";
        a.swap(b);
    }
}

//////////////// non-template version
class WidgetImpl {
private:
    std::vector<int> v;
};

class Widget {
public:
    Widget& operator=(const Widget& rhs)
    {
        *pImpl = *(rhs.pImpl);
        return *this;
    }
    void swap(Widget& other)
    {
        std::cout << "Widget::swap\n";
        using std::swap;
        swap(pImpl, other.pImpl);
    }
private:
    WidgetImpl *pImpl;
};

namespace std {
void swap(Widget& a, Widget& b)
{
    std::cout << "std::swap(Widget& a, Widget& b)\n";
    a.swap(b);
}
}

int main() {
    using std::swap;

    WidgetStuff::WidgetTP<int> a, b;
    swap(a, b);

    Widget c, d;
    swap(c, d);

    return 0;
}