#include <iostream>
#include <type_traits>
#include <functional>

class Empty {};


// primary 버전은 선언만 합니다.(구조체 구현이 없습니다.)
template<typename T1, typename T2, bool = std::is_empty_v< T1  > >
struct compressed_pair;


// 1번째 인자가 empty 아닐때 : <T1, T2, false>
template<typename T1, typename T2>
struct compressed_pair<T1, T2, false>
{
    T1 first;
    T2 second;
};

// 1번째 인자가 empty 일때 : <T1, T2, true>
template<typename T1, typename T2> 
struct compressed_pair<T1, T2, true> : public T1
{
    T2 second;
};





int main()
{
    compressed_pair<Empty, int> p2;    

    std::cout << sizeof(p2) << std::endl; // 4
}

