#include <iostream>

int main()
{
	int n = 10;

	// �ٽ� 1. Ÿ������ �����ϱ�
	// => std::type_info �� ���� �ɼ� �����ϴ�. const & �θ� �޾ƾ� �մϴ�.
	const std::type_info& t1 = typeid(n);	// typeid(����)
	const std::type_info& t2 = typeid(int);	// typeid(Ÿ��)

	// type_info �� == ���� �����մϴ�.
	if (t1 == t2) {}	// �ᱹ, ���ڵ�� "n �� int �ΰ� ����" �ϴ°�

	std::cout << t1.name() << std::endl;
}