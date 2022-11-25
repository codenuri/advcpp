#include <vector>
#include <iostream>

// 핵심 1. 클래스안에 reference 멤버가 있으면
// => 복사 생성자와 대입연산자는 삭제 됩니다
// => 필요하면 사용자가 만들어야 합니다.

template<typename T>
class reverse_view
{
	T& rng;
public:
	reverse_view(T& r) : rng(r) {}
	auto begin() { return rng.rbegin(); }
	auto end() { return rng.rend(); }

	reverse_view& operator=(const reverse_view& other)
	{
		rng = other.rng;	// 문제는 이코드가 rng 가 가리키는
							// vector 의 복사 라는 점.!

		return *this;
	}
};



int main()
{
	std::vector v1 = { 1, 2, 3 };
	std::vector v2 = { 1, 2, 3, 4, 5 };

	reverse_view rv1(v1);
	reverse_view rv2(v2);

	rv1 = rv2;	// 어떻게 동작해야 할까요 ?
}

