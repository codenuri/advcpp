#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vi(10);
	std::vector<bool> vb(10);

	auto a1 = vi[0]; // int
	auto a2 = vb[0]; // bool �ƴմϴ�. proxy �Դϴ�.

	std::cout << typeid(a1).name() << std::endl; // int
	std::cout << typeid(a2).name() << std::endl; // proxy!

	for (auto& e : vi) // ok
	{
	}

//	for (auto& e : vb)  // error. vb ���� �����ϸ� proxy �ӽð�ü�� ��ȯ
						//      �ӽð�ü�� rvalue �̹Ƿ� auto& �� ������ �����ϴ�
	for (auto&& e : vb) // ok
	{
	}

}
