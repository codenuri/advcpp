
#include <iostream>

struct identity
{
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

	std::cout << &n    << std::endl;
	std::cout << &f(n) << std::endl;
	
}