#include <iostream>

// �Ʒ� ������ C++14 �������� ����� �����Դϴ�.
template <typename T = void>
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
    [[nodiscard]] constexpr auto operator()(T1&& lhs,T2&& rhs) const 
        noexcept( noexcept(std::forward<T1>(lhs) < std::forward<T2>(rhs)) )
        -> decltype(std::forward<T1>(lhs) < std::forward<T2>(rhs))
    {
        return std::forward<T1>(lhs) < std::forward<T2>(rhs);
    }
};

int main()
{
    less<int> f1;
    bool ret1 = f1(10, 10.5); // false !

    //----------------------------------
//  less<void> f2;
//  less<>     f2; // Ÿ�����ڸ� �������� �ʾ����Ƿ� ����Ʈ��(void ���)
    less       f2; // C++17 ���ʹ� <> ��ü�� ��������
                   // �ᱹ �� ǥ����� less<void> �� ����ϰڴٴ� �ǹ�

    bool ret2 = f2(10, 10.5);   // true

    std::cout << ret2 << std::endl;
}