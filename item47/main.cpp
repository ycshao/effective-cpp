#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d,
               std::random_access_iterator_tag)
{
    std::cout << "random_access_iterator_tag\n";
    iter += d;
}

template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d,
               std::bidirectional_iterator_tag)
{
    std::cout << "bidirectional_iterator_tag\n";
    if (d >= 0) { while (d--) ++iter; }
    else { while (d++) --iter;         }
}

template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d,
               std::input_iterator_tag)
{
    std::cout << "input_iterator_tag\n";
    if (d < 0 ) {
        throw std::out_of_range("Negative distance");
    }
    while (d--) ++iter;
}

template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d,
               std::output_iterator_tag)
{
    std::cout << "output_iterator_tag\n";
    if (d < 0 ) {
        throw std::out_of_range("Negative distance");
    }
    while (d--) ++iter;
}

template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d,
               std::forward_iterator_tag)
{
    std::cout << "forward_iterator_tag\n";
    if (d < 0 ) {
        throw std::out_of_range("Negative distance");
    }
    while (d--) ++iter;
}

template<typename IterT, typename DistT>
void advance(IterT& iter, DistT d)
{
    std::cout << "---advance---\n";
    doAdvance(iter, d,
              typename std::iterator_traits<IterT>::iterator_category());
};

int main() {

    std::vector<int> intVector;
    std::vector<int>::const_iterator itVector = intVector.begin();
    advance(itVector, 0);

    int* intPtr = NULL;
    advance(intPtr, 0);

    std::list<int> intList;
    std::list<int>::const_iterator itList = intList.begin();
    advance(itList, 0);

    std::unordered_set<int> intSet;
    std::unordered_set<int>::const_iterator itSet = intSet.begin();
    advance(itSet, 0);

    std::ostream_iterator<int> otIS(std::cout, " ");
    advance(otIS, 0);

    std::istream_iterator<int> itIS;
    advance(itIS, 0);

    return 0;
}

