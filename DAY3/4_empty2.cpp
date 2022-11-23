#include <iostream>
#include <type_traits>

// �Ʒ� �ڵ忡�� 
// Ex  : empty
// NEx : empty �ƴ� ���

class  E1 {};
struct E2 {};
union NE1 {};   // union �� empty�� �з� ���� �ʽ��ϴ�.

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
    int data;   // instance member data �� �����Ƿ� empty �ƴ�
};

class NE3
{
    virtual void func() {}
};

class E4  : public E2 {};

class NE4 : virtual public E2 {}; // ���� ����� ����ص�
                                  // �����Լ� ���̺�� �����ϰ� ���� �˴ϴ�.

class NE5
{
    E1 e1;  // empty �� 1����Ʈ�� ����ϹǷ� NE5 ��ü�� empty �� �ƴմϴ�.
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