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

struct zero_and_variadic { explicit zero_and_variadic() = default; };
struct one_and_variadic { explicit one_and_variadic() = default; };

constexpr zero_and_variadic zero_and_var;
constexpr one_and_variadic  one_and_var;


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
    compressed_pair(one_and_variadic, U1&& a, U2&& ... args)
        : first(std::forward<U1>(a)), second(std::forward<U2>(args)...)
    {}

    template<typename ... U2>
    compressed_pair(zero_and_variadic, U2&& ... args)
        : first(), second(std::forward<U2>(args)...)
    {}
};

// T1 �� empty �϶� 
template<typename T1, typename T2>
struct compressed_pair<T1, T2, true> : public T1
{
    T2 second;

    T1& get_first() { return *this; }
    T2& get_second() { return second; }

    const T1& get_first() const { return *this; }
    const T2& get_second()const { return second; }

    template<typename U1, typename ... U2>
    compressed_pair(one_and_variadic, U1&& a, U2&& ... args)
        : T1(std::forward<U1>(a)), second(std::forward<U2>(args)...)
    {}

    template<typename ... U2>
    compressed_pair(zero_and_variadic, U2&& ... args)
        : T1(), second(std::forward<U2>(args)...)
    {}
};
// ����� move �迭 �Լ��� �ϳ��� ������ �ʾҽ��ϴ�.
// => �����Ϸ��� ����Ʈ ���� ��� �����մϴ�
// => ��, �� compressed_pair �� move�� �Ϻ��� �����ϴ� Ŭ���� �Դϴ�.

int main()
{
    compressed_pair<int, Point> p1(one_and_var, 10, 1, 2); // 10, Point(1,2) �ǹ�
    compressed_pair<int, Point> p2(one_and_var, 10);       // 10, Point() �ǹ�
    compressed_pair<int, Point> p4(zero_and_var, 1, 2);     // Point(1,2) �ǹ̷� �Ҽ� ������?

    compressed_pair<Empty, int> p5(zero_and_var, 1);     

}

