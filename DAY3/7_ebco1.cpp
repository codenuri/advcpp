#include <iostream>

// EBCO : Empty Base Class Optimization
//        => Empty 로 부터 상속 받으면 empty 크기는 0이 된다.!

struct Empty {};

// Empty 를 1번째 멤버로 포함하는 경우
struct Data1
{
    Empty e;        // 이 멤버의 주소와
    int   data;     // 이 멤버의 주소는 달라야 합니다.
                    // 따라서 e 도 자신만의 메모리가 있어야 합니다.
};                  


// Empty 로 부터 상속 받는 경우
struct Data2 : public Empty
{
    int   data;  
};

int main()
{
    std::cout << sizeof(Data1) << std::endl; // 8
    std::cout << sizeof(Data2) << std::endl; // 4
}
