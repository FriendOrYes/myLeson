#include <iostream>
#include <algorithm>
#include <numeric>
#include <assert.h>

using namespace std;

template <unsigned, unsigned, unsigned >
class Range;

template<typename T, typename RetT = T>
class range_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
public:
    range_iterator()
        : m_current (0)
        , m_next(1)
    {
    }

    range_iterator(T num, T h)
        : m_current (num)
        , m_next(h)
    {
    }

    RetT& operator*()
    {
        return m_current;
    }

    range_iterator& operator++()
    {
        m_current += m_next;
        return *this;
    }

    range_iterator operator++(int)
    {
        range_iterator tmp(m_current);
        ++(*this);
        return tmp;
    }

    bool operator == (const range_iterator& rhs)
    {
        return m_current == rhs.m_current ;
    }

    bool operator > (const range_iterator& rhs)
    {
        return (m_current > rhs.m_current);
    }

    bool operator < (const range_iterator& rhs)
    {
        return !(*this > rhs);
    }

    bool operator <= (const range_iterator& rhs)
    {
        return (*this < rhs || *this == rhs);
    }

    bool operator >= (const range_iterator& rhs)
    {
        return (*this > rhs || *this == rhs);
    }

    bool operator != (const range_iterator& rhs)
    {
        return !(*this >= rhs);
    }

private:
        T m_current;
        T m_next;
};

//template<typename T, typename RetT = T>
//class range_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
//{
//public:
//    range_iterator()
//        : m_current (0)
//        , m_next(1)
//        , m_counter(0)
//    {
//    }

//    range_iterator(T num, T h)
//        : m_current (num)
//        , m_next(h)
//        , m_counter(0)
//    {
//    }

//    RetT& operator*()
//    {
//        CalculateValue();
//        return m_value;
//    }

//    void CalculateValue()
//    {
//        m_value = m_current + m_counter*m_next;
//    //    cout << "m_value: " << m_value  << endl;
//    }

//    range_iterator& operator++()
//    {
//        m_counter++;
//        return *this;
//    }

//    range_iterator operator++(int)
//    {
//        range_iterator tmp(m_current);
//        ++(*this);
//        return tmp;
//    }

//    bool operator == (const range_iterator& rhs)
//    {
//        CalculateValue();
//        return m_value == rhs.m_current ;
//    }

//    bool operator > (const range_iterator& rhs)
//    {
//        CalculateValue();
//        return (m_value > rhs.m_current);
//    }

//    bool operator < (const range_iterator& rhs)
//    {
//        //cout << __FUNCTION__ << endl;
//        return (*this != rhs);
//    }

//    bool operator <= (const range_iterator& rhs)
//    {

//        //cout << __FUNCTION__ << endl;
//        return (*this < rhs || *this == rhs);
//    }

//    bool operator >= (const range_iterator& rhs)
//    {
//        //cout << __FUNCTION__ << endl;
//        return (*this > rhs || *this == rhs);
//    }

//    bool operator != (const range_iterator& rhs)
//    {
//        //cout << __FUNCTION__ << endl;
//        return !(*this >= rhs);
//    }

//private:
//        T m_current;
//        T m_next;
//        size_t m_counter;
//        T m_value;
//};


template <unsigned int B, unsigned int E, unsigned int S = 1>
class Range
{
public:
    typedef range_iterator<int> iterator;
    Range(){}

    iterator begin() const
    {
        return iterator(B, S);
    }

    iterator end() const
    {
        return iterator(E, S);
    }

    unsigned int& front()
    {
        return B;
    }

    unsigned int& back() const
    {
        return E;
    }
private:
};

int main(int argc, char *argv[])
{

//    Range<1, 5> r;
//    for(auto it = r.begin(); it != r.end(); ++it)
//    {
//        cout << *it << endl;
//    }
    for (auto& elem : Range<1, 5>())
    {
        cout << elem << " "; // 1 2 3 4
    }

    cout << endl;
    for (auto& elem : Range<0, 10, 2>())
    {
        cout << elem << " "; //0 2 4 6 8
    }

    cout << endl;
    for (auto& elem : Range<20, 50, 1000>())
    {
        cout << elem << " "; // 20
    }
    cout << endl;


    auto r1 = Range<1,30>();
    for(auto it = r1.begin(); it != r1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << count_if(r1.begin(), r1.end(), [](int e){return e>20;}) << endl; // 9

    assert(accumulate(r1.begin(), r1.end(), 0) == ((1 + 29)*1.0 / 2) * 29);


    assert(any_of(r1.begin(), r1.end(), [](unsigned int elem)
    {
        cout << (elem > 29)<< " ";
        return elem > 29;
    }) == false);

    cout << endl;
    assert(all_of(r1.begin(), r1.end(), [](unsigned int elem)
    {
        cout << (elem > 0)<< " ";
        return elem > 0;
    }) == true);

    cout << endl;
    return 0;
}
