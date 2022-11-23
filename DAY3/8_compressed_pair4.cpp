#include <iostream>
#include <type_traits>
#include <functional>

class Empty {};


struct Point
{
    int x, y;
    Point() : x(0), y(0) {}

    Point(int a, int b) : x(a), y(b) {}
};


template<typename T1, typename T2, bool = std::is_empty_v< T1  > >
struct compressed_pair;


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

    template<typename ... U2>
    compressed_pair(U2&& ... args)
        : first(), second(std::forward<U2>(args)...)
    {}
};

int main()
{
    compressed_pair<int, Point> p1(10, 1, 2); // 10, Point(1,2) 의미
    compressed_pair<int, Point> p2(10);       // 10, Point() 의미
    compressed_pair<int, Point> p4(1, 2);     // Point(1,2) 의미로 할수 없을까?
                            // error.       
                            // 이 코드는 위 2개의 생성자가 모두 사용가능합니다
                            // "ambiguous" error

}

