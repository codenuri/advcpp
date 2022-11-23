#include <iostream>
#include <type_traits>
#include <functional>

class Empty {};


// primary ������ ���� �մϴ�.(����ü ������ �����ϴ�.)
template<typename T1, typename T2, bool = std::is_empty_v< T1  > >
struct compressed_pair;


// 1��° ���ڰ� empty �ƴҶ� : <T1, T2, false>
template<typename T1, typename T2>
struct compressed_pair<T1, T2, false>
{
    T1 first;
    T2 second;
};

// 1��° ���ڰ� empty �϶� : <T1, T2, true>
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

