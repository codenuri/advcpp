#include <iostream>
#include <type_traits>

// empty class 
// => non-static ��� ����Ÿ�� ����
// => �����Լ��� ���� Ŭ����
// => sizeof(empty) �� ũ�Ⱑ 1�Դϴ�.

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

    // empty Ÿ�� ���θ� �����ϴ� ���
    std::cout << std::is_empty_v<Empty> << std::endl;       // true 1
    std::cout << std::is_empty_v<NoEmpty> << std::endl;     // false 0

}