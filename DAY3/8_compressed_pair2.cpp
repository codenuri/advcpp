#include <iostream>
#include <type_traits>
#include <functional>

class Empty {};


template<typename T1, typename T2, bool = std::is_empty_v< T1  > >
struct compressed_pair;


template<typename T1, typename T2>
struct compressed_pair<T1, T2, false>
{
    T1 first;
    T2 second;
};

int main()
{
    compressed_pair<int, int> p;

    std::cout << sizeof(p) << std::endl; 
}

