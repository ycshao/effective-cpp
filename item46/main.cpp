#include <iostream>

class Rational {
public:
    Rational(int numerator = 0,
             int denominator = 1)
    : m_numerator(numerator)
    , m_denominator(denominator){}

    int numerator() const{return m_numerator;}
    int denominator() const{return m_denominator;}

private:
    int m_numerator;
    int m_denominator;
};

const Rational operator*(const Rational &lhs, const Rational &rhs) {
    return Rational(lhs.numerator() * rhs.numerator(),
                    lhs.denominator() * rhs.denominator());
}

template <typename T>
class RationalTP {
public:
    RationalTP(const T& numerator = 0,
               const T& denominator = 1)
            : m_numerator(numerator)
            , m_denominator(denominator){}

    const T numerator() const{return m_numerator;}
    const T denominator() const{return m_denominator;}

    friend const RationalTP operator*(const RationalTP &lhs, const RationalTP &rhs) {
        return RationalTP(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
    }
private:
    T m_numerator;
    T m_denominator;
};

// With this free operator*, resultTP = oneHalfTP * 2 and
// resultTP = 2 * oneHalfTP won't compile
//template <typename T>
//const RationalTP<T> operator*(const RationalTP<T> &lhs, const RationalTP<T> &rhs) {
//    return RationalTP<T>(lhs.numerator() * rhs.numerator(),
//                    lhs.denominator() * rhs.denominator());
//}

int main() {

    Rational oneHalf(1, 2);
    Rational oneEighth(1, 8);
    Rational result = oneHalf * oneEighth;
    result = result * oneEighth;

    result = oneHalf * 2;
    result = 2 * oneHalf;

    RationalTP<int> oneHalfTP(1, 2);
    RationalTP<int> oneEighthTP(1, 8);
    RationalTP<int> resultTP = oneHalfTP * oneEighthTP;
    resultTP = resultTP * oneEighthTP;

    resultTP = oneHalfTP * 2;
    resultTP = 2 * oneHalfTP;

    return 0;
}

