#include <iostream>

class Top {};
class Middle: public Top {};
class Bottom: public Middle {};

// This won't work very well
//template<typename T>
//class SmartPtr {
//public:
//    explicit SmartPtr(T *realPtr){};
//};


template<typename T>
class SmartPtr {
public:
    explicit SmartPtr(T *realPtr){}
    SmartPtr(SmartPtr const& r){};
    template<typename U>
    SmartPtr(const SmartPtr<U>& other)
            : heldPtr(other.get()) {}

    SmartPtr& operator=(SmartPtr const& r){};
    template<typename Y>
    SmartPtr& operator=(SmartPtr<Y> const& r){};

    T* get() const { return heldPtr; }
private:
    T *heldPtr;
};

int main() {

    Top *pt1 = new Middle;
    Top *pt2 = new Bottom;
    const Top *pct2 = pt1;

    SmartPtr<Top> smartPtr1 = SmartPtr<Middle>(new Middle);
    SmartPtr<Top> smartPtr2 = SmartPtr<Bottom>(new Bottom);
    SmartPtr<const Top> smartPctr2 = smartPtr1;

    return 0;
}

