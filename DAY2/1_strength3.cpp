// noexcept
#include <iostream>

// 함수가 예외가 없다면, 컴파일러에게 예외가 없다고 알려 주는 것이 좋습니다.
// => 최적화에 도움이 되고 ( godbolt.org )

// noexcept 1. 함수 () 뒤에 붙여서 예외가 없음을 알릴때 사용
void f1() noexcept {}         // 예외가 없다
void f1() noexcept(false) {}  // 예외가 있다
void f1() noexcept(true)  {}  // 예외가 없다

// noexcept 2. "표현식이 예외가 있는지 없는지 조사"

bool b1 = noexcept( 3 + 2 );        // true
bool b2 = noexcept( new int[100] ); // false




template<typename T>
[[nodiscard]] constexpr const T& 
max(const T& lhs, const T& rhs) 
{
	return lhs < rhs ? rhs : lhs;
}

int main()
{
	auto ret = max(1, 2);

	std::cout << ret << std::endl;


}