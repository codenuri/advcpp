#include <iostream>

// 아래 구현은 C++14 버전에서 변경된 내용입니다.
template <typename T = void>
struct less
{
    inline bool operator()(const T& lhs, const T& rhs) const
    {
        return lhs < rhs;
    }
};

// "less<void>" 처럼 사용될때를 위한 특수화(specialization) 버전
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
//  less<>     f2; // 타입인자를 전달하지 않았으므로 디폴트값(void 사용)
    less       f2; // C++17 부터는 <> 자체도 생략가능
                   // 결국 이 표기법이 less<void> 를 사용하겠다는 의미

    bool ret2 = f2(10, 10.5);   // true

    std::cout << ret2 << std::endl;
}