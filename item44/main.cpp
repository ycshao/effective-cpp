#include <iostream>
#include <string>
#include <boost/scoped_array.hpp>

template<typename T, std::size_t n>
class SquareMatrix {
public:
    void invert(){}
};

template<typename T>
class SquareMatrixBase {
protected:
    SquareMatrixBase(std::size_t n, T *pMem)
    : size(n)
    , pData(pMem) {}
    void setDataPtr(T *ptr) { pData = ptr; }
    void invert(std::size_t matrixSize){}
private:
    std::size_t size;
    T *pData;
};

template<typename T, std::size_t n>
class SquareMatrixBetter: private SquareMatrixBase<T> {
private:
    using SquareMatrixBase<T>::invert;
public:
    SquareMatrixBetter()
    : SquareMatrixBase<T>(n, 0)
    , pData(new T[n*n])
    { this->setDataPtr(pData.get()); }
    void invert() {this->invert(n);}
private:
    boost::scoped_array<T> pData;
};

int main() {
    SquareMatrixBetter<double, 5> sm1;
    sm1.invert();
    SquareMatrixBetter<double, 10> sm2;
    sm2.invert();
    return 0;
}

