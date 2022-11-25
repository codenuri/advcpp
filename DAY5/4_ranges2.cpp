#include <vector>
#include <iostream>

// view : 컨테이너를 바라 보는 "시각"
//		  자원을 소유하지 않은 "range"

template<typename T> 
class reverse_view
{
	T& rng;
public:
	reverse_view(T& r) : rng(r) {}

	auto begin() { return rng.rbegin(); }
	auto end()   { return rng.rend(); }
};

int main()
{
	std::vector v = { 1, 2, 3, 4, 5 };

//	reverse_view rv(v); // C++17 부터 템플릿 인자 생략가능합니다.

//	for (auto e : rv )
	for (auto e : reverse_view(v) )
	{
		std::cout << e << std::endl;
	}

}

