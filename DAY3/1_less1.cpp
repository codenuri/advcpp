#include <iostream>

// less �Լ� ��ü : ����Ÿ���� ��ü 2���� ���ؼ� < ������ �����ϴ� �Լ���ü
//              => set ���� �����̳��� ũ�� �񱳿� ���
//              => C++98 ǥ��

// �Ʒ� �ڵ尡 C++98 ������ �����Դϴ�.
template <typename T>
struct less
{
    inline bool operator()(const T& lhs, const T& rhs) const
    {
        return lhs < rhs;
    }
};
int main()
{
    less<int> f;

    bool ret1 = f(10, 20);      // true
    bool ret2 = f(10, 10.5);    // false �Դϴ�.

    std::cout << ret1 << std::endl;
    std::cout << ret2 << std::endl;
}