#include <iostream>
#include <type_traits>
#include <functional>

class Empty {};


template<typename T1, typename T2, bool = std::is_empty_v< T1  > >
struct compressed_pair;

// empty °¡ ¾Æ´Ò¶§.. 
template<typename T1, typename T2>
struct compressed_pair<T1, T2, false>
{
    T1 first;
    T2 second;

    T1& get_first() { return first; }
    T2& get_second() { return second; }

    const T1& get_first() const { return first; }
    const T2& get_second()const { return second; }

    template<typename U1, typename U2>
    compressed_pair(U1&& a, U2&& b)
        : first(std::forward<U1>(a)), second(std::forward<U2>(b))
    {}
};

struct Point
{
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
};

int main()
{
    compressed_pair<int, Point> p1(3, Point(1, 2));

    
}

