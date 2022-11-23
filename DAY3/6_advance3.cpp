#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// C++11
// => xadvance 만 2개 만들자!
// => enable_if_t 로 조건을만족하는 경우만 사용

template<typename T>
std::enable_if_t< std::is_same_v< 
			typename std::iterator_traits<T>::iterator_category, 
			std::random_access_iterator_tag>  >
xadvance(T& p, int sz)
{
	std::cout << "+ 로 이동" << std::endl;
	p = p + sz;
}

template<typename T>
std::enable_if_t< !std::is_same_v<
	typename  std::iterator_traits<T>::iterator_category,
	std::random_access_iterator_tag>  >
xadvance(T& p, int sz)
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
