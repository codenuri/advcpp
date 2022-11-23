#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// C++17. if constexpr 사용해서 조사

template<typename T>
void xadvance(T& p, int sz)
{
	if ( std::is_same_v<
					typename  std::iterator_traits<T>::iterator_category,
					std::random_access_iterator_tag> )
	{
		std::cout << "+ 로 이동" << std::endl;
		p = p + sz;
	}
	else
	{
		std::cout << "++ 로 이동" << std::endl;
		while (sz--) ++p;
	}
}

int main()
{
	//std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };
	auto p = s.begin();

//	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	auto p = std::begin(x);

	xadvance(p, 5);


	std::cout << *p << std::endl;
}
