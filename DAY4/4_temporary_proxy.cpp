#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vi(10);
	std::vector<bool> vb(10);

	auto a1 = vi[0]; // int
	auto a2 = vb[0]; // bool 아닙니다. proxy 입니다.

	std::cout << typeid(a1).name() << std::endl; // int
	std::cout << typeid(a2).name() << std::endl; // ??
}
