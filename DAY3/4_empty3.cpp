#include <iostream>
#include <functional>
#include <type_traits>

// C++에는 empty class 가 많이 사용됩니다.
int main()
{
    // C++98 부터 제공되는 "함수객체" 가 모두 empty 입니다.
    std::plus<int>    f1;
    std::modulus<int> f2;
    std::less<int>    f5;

    // 지역변수 캡쳐를 사용하지 않은 람다표현식이 만드는 타입도 empty 입니다.
    int v = 0;
    auto f3 = [ ](int a, int b) { return a + b;};
    auto f4 = [v](int a, int b) { return a + b + v;};


    // C++ 표준의 allocator 도 empty 입니다.
    std::allocator<int> ax;

    std::cout << std::boolalpha;
    std::cout << std::is_empty_v< decltype(f1) > << std::endl;
    std::cout << std::is_empty_v< decltype(f2) > << std::endl;
    std::cout << std::is_empty_v< decltype(f3) > << std::endl;  
    std::cout << std::is_empty_v< decltype(f4) > << std::endl; // false 
    std::cout << std::is_empty_v< decltype(ax) > << std::endl;   
}