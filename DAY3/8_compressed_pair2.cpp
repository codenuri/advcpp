#include <iostream>
#include <type_traits>
#include <functional>

class Empty {};


template<typename T1, typename T2, bool = std::is_empty_v< T1  > >
struct compressed_pair;

// empty 가 아닐때.. 
template<typename T1, typename T2>
struct compressed_pair<T1, T2, false>
{
    T1 first;
    T2 second;

    T1& get_first()  { return first; }
    T2& get_second() { return second; }

    const T1& get_first() const { return first; }
    const T2& get_second()const { return second; }

    // 아래 생성자는 "move" 지원이 안됩니다. - modern C++ 참고!
    // compressed_pair<string, string> p(std::move(s1), std::move(s2));
    // compressed_pair(const T1& a, const T2& b) : first(a), second(b) {}

    template<typename U1, typename U2>
    compressed_pair(U1&& a, U2&& b)
        : first(std::forward<U1>(a)),
          second(std::forward<U2>(b)) 
    {}
};


int main()
{
    compressed_pair<int, int> p(3, 4);

    std::cout << sizeof(p) << std::endl; 
}

