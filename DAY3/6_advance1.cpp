#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// C++98 ������ ���� ���

// empty Ŭ������ ����ؼ� �ݺ����� 5���� ������ Ÿ��ȭ �մϴ�.

struct input_iterator_tag {};	// �Է� �ݺ���
struct output_iterator_tag {};	// ��� �ݺ���
struct forward_iterator_tag : input_iterator_tag {}; // ������
struct bidirectional_iterator_tag : forward_iterator_tag {}; // �����
struct random_access_iterator_tag : bidirectional_iterator_tag  {}; // ��������


template<typename T> 
void advance(T& p, int sz)
{
	p = p + sz;
}

int main()
{
	//	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = s.begin();

	xadvance(p, 5); 


	std::cout << *p << std::endl;
}
