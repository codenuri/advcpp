// 1_new10
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v1(1000); // 1000 �� �޸� �Ҵ� + ������ ȣ��

	std::vector<int> v2;
	v2.reserve(1000);	// 1000�� �޸𸮸� �Ҵ�
						// capacity = 1000, size = 0

}