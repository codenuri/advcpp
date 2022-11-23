#include <iostream>
#include <type_traits>

// empty class 
// => non-static 멤버 데이타가 없고
// => 가상함수도 없는 클래스
// => sizeof(empty) 는 크기가 1입니다.

class Empty 
{    
};

class NoEmpty 
{
    int data;
};

int main()
{
    Empty e;
    std::cout << sizeof(Empty)   << std::endl; // 1
    std::cout << sizeof(NoEmpty) << std::endl; // 4

    // empty 타입 여부를 조사하는 방법
    std::cout << std::is_empty_v<Empty> << std::endl;       // true 1
    std::cout << std::is_empty_v<NoEmpty> << std::endl;     // false 0

}