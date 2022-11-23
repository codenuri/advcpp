#include <iostream>
#include <type_traits>
#include <functional>

class Empty {};


struct Point
{
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
};


template<typename T1, typename T2, bool = std::is_empty_v< T1  > >
struct compressed_pair;

// empty 가 아닐때.. 
template<typename T1, typename T2>
struct compressed_pair<T1, T2, false>
{
    T1 first;
    T2 second;

    T1& get_first() { return first; }
    T2& get_second() { return second; }

    const T1& get_first() const { return first; }
    const T2& get_second()const { return second; }

    template<typename U1, typename ... U2>
    compressed_pair(U1&& a, U2&& ... args)
        : first(std::forward<U1>(a)), second(std::forward<U2>(args)...)
    {}
};

int main()
{
    compressed_pair<int, Point> p1(3, Point(1, 2) );

    compressed_pair<int, Point> p2(3, 1, 2); // Point 만들때 필요한 생성자
                                            // 인자를 전달

    
}

