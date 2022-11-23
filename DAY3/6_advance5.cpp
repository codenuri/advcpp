#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// C++17 ���� : �ݺ��� �����ڰ� �ڽ��� � ������ �ݺ�������
//				�˷��־�� �մϴ�.

// C++20 ���� : �˷����� �ʾƵ� ���� �����մϴ�.
//			   => C++20 concept
//			   => haskell �� ��Ÿ Ŭ���� ����
//			   => rust �� "traits" ����

// �������� �ݺ��ڰ� ������ �ϴ� Ư¡�� "����" �մϴ�.
// => ������ ���� ��� �մϴ�.
template<typename T>
concept random_access_iterator = requires(T& p)
{
	++p;
	p++;
	--p;
	p--;
	p + 1;
	*p;
};

template<typename T> void check(T& p)
{
	// bool b = �����̸�<Ÿ��>; // Ÿ���� ������ �����ϴ��� ����
	std::cout << random_access_iterator<T> << std::endl;
}
int main()
{
	int n = 10;
	int* p = &n;

	check(n); // int
	check(p); // int*
}