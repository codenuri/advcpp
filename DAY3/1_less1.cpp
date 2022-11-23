#include <iostream>

// less 함수 객체 : 같은타입의 객체 2개에 대해서 < 연산을 수행하는 함수객체
//              => set 같은 컨테이너의 크기 비교에 사용
//              => C++98 표준

// 아래 코드가 C++98 시절의 구현입니다.
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
    bool ret2 = f(10, 10.5);    // false 입니다.

    std::cout << ret1 << std::endl;
    std::cout << ret2 << std::endl;
}