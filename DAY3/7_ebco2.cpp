#include <iostream>
#include <type_traits>
#include <functional>

class Empty {};


template<typename T1, typename T2, bool = std::is_empty_v< T1  > > 
struct PAIR
{
    T1 first;
    T2 second;
};

template<typename T1, typename T2> struct PAIR<T1, T2, true> : public T1
{
    T2 second;
};

int main()
{    
    PAIR<int,   int> p1;    
    std::cout << sizeof(p1) << std::endl; // 8

//    PAIR<Empty, int> p2;    
    PAIR<std::less<int>, int> p2;  // set<int, std::less<int>> 같은 코드!

    std::cout << sizeof(p2) << std::endl; // 4
}
// 위 코드가 "boost 라이브러리" 의 "compressed_pair 개념" 입니다.
// std::vector, std::unique_ptr 등은 모두 "compressed_pair" 를 사용합니다.
