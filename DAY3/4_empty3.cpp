#include <iostream>
#include <functional>
#include <type_traits>

// C++���� empty class �� ���� ���˴ϴ�.
int main()
{
    // C++98 ���� �����Ǵ� "�Լ���ü" �� ��� empty �Դϴ�.
    std::plus<int>    f1;
    std::modulus<int> f2;
    std::less<int>    f5;

    // �������� ĸ�ĸ� ������� ���� ����ǥ������ ����� Ÿ�Ե� empty �Դϴ�.
    int v = 0;
    auto f3 = [ ](int a, int b) { return a + b;};
    auto f4 = [v](int a, int b) { return a + b + v;};


    // C++ ǥ���� allocator �� empty �Դϴ�.
    std::allocator<int> ax;

    std::cout << std::boolalpha;
    std::cout << std::is_empty_v< decltype(f1) > << std::endl;
    std::cout << std::is_empty_v< decltype(f2) > << std::endl;
    std::cout << std::is_empty_v< decltype(f3) > << std::endl;  
    std::cout << std::is_empty_v< decltype(f4) > << std::endl; // false 
    std::cout << std::is_empty_v< decltype(ax) > << std::endl;   
}