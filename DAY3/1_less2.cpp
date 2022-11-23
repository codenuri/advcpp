#include <iostream>

// �Ʒ� ������ C++14 �������� ����� �����Դϴ�.
template <typename T>
struct less
{
    inline bool operator()(const T& lhs, const T& rhs) const
    {
        return lhs < rhs;
    }
};

// "less<void>" ó�� ���ɶ��� ���� Ư��ȭ(specialization) ����
template <> 
struct less<void>
{
    template<typename T1, typename T2>
    inline bool operator()(T1&& lhs,T2&& rhs) const
    {
        return lhs < rhs;
    }
};

int main()
{
    less<void> f;
    bool ret = f(10, 10.5);

    std::cout << ret << std::endl;
}