// 1_new10
#include <vector>
#include <iostream>

int main()
{
	// �ٽ� 1. ũ�⸦ �����ϴ� �Ͱ� �뷮(capacity)�� Ȯ���ϴ� ���� ������
	std::vector<int> v1(1000); // 1000 �� �޸� �Ҵ� + ������ ȣ��
								// capacity=1000, size=1000
	std::vector<int> v2;
	v2.reserve(1000);	// 1000�� �޸𸮸� �Ҵ�
						// capacity = 1000, size = 0

	v2.push_back(10);	// �̼��� ����� Ÿ���̸� ������ ȣ��
						// size=1
	//----------------------------------------------
	// �ٽ� 2. ���� �������� ���� ���
	std::vector<int> v3(10, 0);
	v3.resize(7);

	std::vector<int> v4 = v3;

	std::cout << v3.capacity() << ", " << v3.size() << std::endl; // ?
	std::cout << v4.capacity() << ", " << v4.size() << std::endl; // ?
}