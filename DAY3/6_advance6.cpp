#include <iostream>
#include <vector>
#include <list>

// 앞에서 random_access_iterator concept 를 만들었지만!!
#include <iterator>	// 이미 이 안에 C++20 부터 만들어져 있습니다.
#include <concepts>  // 이 헤더에도 많은 concept 이 만들어져 있습니다.

// std::random_access_iterator_tag : empty class,C++98 에서 만든것
// std::random_access_iterator     : concept, C++20 에서 만든것

/*
template< std::random_access_iterator T>
void xadvance(T& p, int sz)
{
	std::cout << "+ 로 이동" << std::endl;
	p = p + sz;
}

template< std::input_iterator T>
void xadvance(T& p, int sz)
{
	std::cout << "++ 로 이동" << std::endl;
	while (sz--) ++p;
}
*/

// 아래 코드도 결국 위와 동일합니다.
// => 미래에는 아래처럼 만들게 됩니다.
// => template 표기가 없지만 아래 코드는 "template" 입니다.
void xadvance(std::random_access_iterator auto& p, int sz)
{
	std::cout << "+ 로 이동" << std::endl;
	p = p + sz;
}

void xadvance(std::input_iterator auto& p, int sz)
{
	std::cout << "++ 로 이동" << std::endl;
	while (sz--) ++p;
}


int main()
{
	//std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	//std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };
	//auto p = s.begin();

	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = std::begin(x);

	xadvance(p, 5);


	std::cout << *p << std::endl;
}
