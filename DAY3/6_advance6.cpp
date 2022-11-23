#include <iostream>
#include <vector>
#include <list>

// �տ��� random_access_iterator concept �� ���������!!
#include <iterator>	// �̹� �� �ȿ� C++20 ���� ������� �ֽ��ϴ�.
#include <concepts>  // �� ������� ���� concept �� ������� �ֽ��ϴ�.

// std::random_access_iterator_tag : empty class,C++98 ���� �����
// std::random_access_iterator     : concept, C++20 ���� �����

template< std::random_access_iterator T>
void xadvance(T& p, int sz)
{
	std::cout << "+ �� �̵�" << std::endl;
	p = p + sz;
}

template< std::input_iterator T>
void xadvance(T& p, int sz)
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
