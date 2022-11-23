#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// C++98 ������ ���� ���

// empty Ŭ������ ����ؼ� �ݺ����� 5���� ������ Ÿ��ȭ �մϴ�.
/*
struct input_iterator_tag {};	// �Է� �ݺ���
struct output_iterator_tag {};	// ��� �ݺ���
struct forward_iterator_tag       : input_iterator_tag {}; // ������
struct bidirectional_iterator_tag : forward_iterator_tag {}; // �����
struct random_access_iterator_tag : bidirectional_iterator_tag  {}; // ��������

// ���� �� �����̳��� �ݺ��ڸ� ����� ����� �ݵ�� �ڽ��� � ����������
// ��ӵ� ������� �˷��� �մϴ�.
template<typename T> class vector_iterator
{
public:
	using iterator_category = random_access_iterator_tag;
};

template<typename T> class list_iterator
{
public:
	using iterator_category = bidirectional_iterator_tag;

	//..... �پ��� �ݺ��� ���� ��� �Լ���
};
*/

template<typename T>
void xadvance_imp(T& p, int sz, std::random_access_iterator_tag )
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
	// �ݺ����� ������ ���� �Լ� �����ε��մϴ�.
	// => �ᱹ �ݺ��� �ȿ� "�ڽ��� � ���������� ��Ÿ���� Ÿ��(���̾ƴ�)�� �ְ�!
	// => �Լ� �����ε� ����� �ٸ� ������ ���
	xadvance_imp(p, sz, typename T::iterator_category() );
}


int main()
{
	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	//std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = s.begin();

	xadvance(p, 5); 


	std::cout << *p << std::endl;
}
