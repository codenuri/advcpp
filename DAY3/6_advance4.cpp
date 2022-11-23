#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// C++17. if constexpr ����ؼ� ����

template<typename T>
void xadvance(T& p, int sz)
{
	// if constexpr : ������ �����̸� "���ø� �ν��Ͻ�ȭ"�� ������������� ��
	// ���ø� �ν��Ͻ�ȭ : "���ø� => ���� �Լ�"�� ����� ����

	if constexpr ( std::is_same_v<
					typename  std::iterator_traits<T>::iterator_category,
					std::random_access_iterator_tag> )
	{
		std::cout << "+ �� �̵�" << std::endl;
		p = p + sz;
	}
	else
	{
		std::cout << "++ �� �̵�" << std::endl;
		while (sz--) ++p;
	}
}


int main()
{
//	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };
	auto p = s.begin();

//	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	auto p = std::begin(x);

	xadvance(p, 5);


	std::cout << *p << std::endl;
}
