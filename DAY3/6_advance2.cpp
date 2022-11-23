#include <iostream>
#include <vector>
#include <list>
#include <iterator>


// Ŭ������ ���� �ݺ��ڿ� raw pointer �� �������� �ذ��ϱ� ���� ����
template<typename T> struct iterator_traits
{
	using iterator_category = typename T::iterator_category;
};

// T= raw pointer �϶� ������ �����մϴ�.
template<typename T> struct iterator_traits<T*>
{
	using iterator_category = std::random_access_iterator_tag;
};





template<typename T>
void xadvance_imp(T& p, int sz, std::random_access_iterator_tag)
{
	std::cout << "+ �� �̵�" << std::endl;
	p = p + sz;
}
template<typename T>
void xadvance_imp(T& p, int sz, std::input_iterator_tag)
{
	std::cout << "++ �� �̵�" << std::endl;
	while (sz--) ++p;
}
template<typename T>
void xadvance(T& p, int sz)
{
	// �Ʒ� �ڵ�� T�� Ŭ������ ���� �ݺ��ڸ� �˴ϴ�.
	// T�� "raw pointer" ��� ���� �Դϴ�.
	// xadvance_imp(p, sz, typename T::iterator_category());

	xadvance_imp(p, sz, typename iterator_traits<T>::iterator_category());
}



int main()
{
	//std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	//std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };
	//auto p = s.begin();

	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = std::begin(x); // �Ϲ��Լ� begin ����ϸ� �迭�� �����մϴ�.
							// �ǹ̴� "auto p = x" �� �����ϴ�.
							// ��, p �� "int*" Ÿ���Դϴ�.
	xadvance(p, 5);	


	std::cout << *p << std::endl;
}
