#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// C++11
// => xadvance �� 2�� ������!
// => enable_if_t �� �����������ϴ� ��츸 ���

template<typename T>
std::enable_if_t< std::is_same_v< 
			typename std::iterator_traits<T>::iterator_category, 
			std::random_access_iterator_tag>  >
xadvance(T& p, int sz)
{
	std::cout << "+ �� �̵�" << std::endl;
	p = p + sz;
}

template<typename T>
std::enable_if_t< !std::is_same_v<
	typename  std::iterator_traits<T>::iterator_category,
	std::random_access_iterator_tag>  >
xadvance(T& p, int sz)
{
	std::cout << "++ �� �̵�" << std::endl;
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
