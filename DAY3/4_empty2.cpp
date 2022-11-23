#include <iostream>
#include <type_traits>

// 아래 코드에서 
// Ex  : empty
// NEx : empty 아닌 경우

class  E1 {};
struct E2 {};
union NE1 {};   // union 은 empty로 분류 하지 않습니다.

class E3
{
    static int data;
public:
    E3() {}
    void func() {}
};
int E3::data = 0;

class NE2
{
    int data;   // instance member data 가 있으므로 empty 아님
};

class NE3
{
    virtual void func() {}
};

class E4  : public E2 {};

class NE4 : virtual public E2 {}; // 가상 상속을 사용해도
                                  // 가상함수 테이블과 유사하게 관리 됩니다.

class NE5
{
    E1 e1;  // empty 도 1바이트를 사용하므로 NE5 자체는 empty 가 아닙니다.
};

int main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_empty_v< E1 > << std::endl;
    std::cout << std::is_empty_v< E2 > << std::endl;
    std::cout << std::is_empty_v< E3 > << std::endl;
    std::cout << std::is_empty_v< E4 > << std::endl;

    std::cout << std::is_empty_v< NE1 > << std::endl;
    std::cout << std::is_empty_v< NE2 > << std::endl;
    std::cout << std::is_empty_v< NE3 > << std::endl;
    std::cout << std::is_empty_v< NE4 > << std::endl;
    std::cout << std::is_empty_v< NE5 > << std::endl;
}