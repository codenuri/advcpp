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
	auto end() { return rng.rend(); }
};

template<typename T> 
class take_view
{
	T& rng;
	int count;
public:
	take_view(T& r, int cnt) : rng(r), count(cnt) {}

	auto begin() { return rng.begin(); }
	auto end()   { return std::next(rng.begin(), count) ; }
};

int main()
{
	std::vector v = { 1, 2, 3, 4, 5 };

	take_view tv(v, 3); // v를 3개만 볼수 있는 view

	// range 의 view 는 자원을 소유하지 않으므로
	// 원본 컨테이너 변경시 view 의 결과도 당연히 변경됩니다
	v[0] = 100; 

	for (auto e : tv )
	{
		std::cout << e << std::endl;
	}

}

