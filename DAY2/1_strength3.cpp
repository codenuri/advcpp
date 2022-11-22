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
//===================================================
// lhs < rhs
// => int, double 등의 타입이라면 예외 없음이 보장되지만
// => user define type 이라면 "operator<()" 함수가 예외가 있을수도 있고
//    없을수도 있습니다.
// => "operator<()"			 : 예외가 있다.
// => "operator<() noexcept" : 예외가 없다.
// => 따라서, "operator<()" 만들때도 "noexcept" 를 붙이는 것이 좋은 코드

template<typename T>
[[nodiscard]] constexpr const T& 
max(const T& lhs, const T& rhs) noexcept( noexcept( lhs < rhs ) )
{
	return lhs < rhs ? rhs : lhs;
}




int main()
{
	auto ret = max(1, 2);

	std::cout << ret << std::endl;


}