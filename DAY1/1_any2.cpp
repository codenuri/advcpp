#include <iostream>

int main()
{
	int n = 10;

	// �ٽ� 1. Ÿ������ �����ϱ�
	const std::type_info& t1 = typeid(n);
	const std::type_info& t2 = typeid(int);
}