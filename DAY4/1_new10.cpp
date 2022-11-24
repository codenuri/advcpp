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

	std::vector<int> v4 = v3;	// ���� ���� 
								// ��, capacity ũ�� ��ü�� �ƴ�
								// size ũ���� �޸𸮸� ����!

	std::cout << v3.capacity() << ", " << v3.size() << std::endl; // 10, 7
	std::cout << v4.capacity() << ", " << v4.size() << std::endl; // 7, 7

	// ==============================
	// �ٽ� 3. swap ��� �Լ� - ������ ��ȯ
	v3.swap(v4); 

	std::cout << v3.capacity() << ", " << v3.size() << std::endl; // 
	std::cout << v4.capacity() << ", " << v4.size() << std::endl; //

	// �ٽ� 4. �ӽð�ü ������ swap ��� ���� 
	// => effective STL �� �Ұ��� ���� ������ ���..
	std::vector<int> v5(10);
	v5.resize(5);


	// case 1. �ʿ���� capacity �����ϱ�
	std::vector<int>(v5).swap(v5);
			// => 1. v5�� �����ؼ� �ӽð�ü ����
			// => 2. v5�� �ӽð�ü�� ���� ��ȯ
			// => 3. ������ ������ �ӽð�ü �ı�, �ڽ��� ���� ����

	std::cout << v5.capacity() << ", " << v5.size() << std::endl;


	// case 2. �޸� ��������
	// => �ӽð�ü ������, ���� �����ڰ� �ƴ� ����Ʈ ������ ���
	std::vector<int>().swap(v5);

	
	// �ٽ� 5. vector �� �޸𸮸� ���� �����Ϸ���
	
	std::vector<int> v6(10);
	
	// ���1. clear, shink_to_fit()
	v6.clear();			// size �� 0���� �ϰ�
	v6.shrink_to_fit();	// capacity �� size �� �����ϰ�.


	// ��� 2. �� vector �ֱ�
	v6 = std::vector<int>();


	// ��� 3. �ӽð�ü swap
	std::vector<int>().swap(v6);
}