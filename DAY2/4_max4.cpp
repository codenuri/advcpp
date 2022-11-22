
#include <iostream>

struct identity
{
	// T&& : 모든 타입의 모든 객체를 받겠다는 의미
	// return std::forward<T>(obj) : 처음 인자로 받은 객체를
	//								어떠한 변화도 없이 반환하겠다는 것
	template<typename T>
	constexpr T&& operator()(T&& obj) const noexcept
	{
		return std::forward<T>(obj);
	}
};

int main()
{
	identity f;

	int n = 10;

	f(n);	// f 의 결과로 다시 n 를 반환 합니다.
			// => n에 대한 어떠한 변화도 없이 동일한 객체를 반환 합니다.

	std::cout << &n    << std::endl;
	std::cout << &f(n) << std::endl;
	
}