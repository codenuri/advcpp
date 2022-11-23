#include <iostream>

// 아래 구현은 C++14 버전에서 변경된 내용입니다.
template <typename T>
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