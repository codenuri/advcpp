#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vi(10);
	std::vector<bool> vb(10);

	auto a1 = vi[0]; // int
	auto a2 = vb[0]; // bool 아닙니다. proxy 입니다.

	std::cout << typeid(a1).name() << std::endl; // int
	std::cout << typeid(a2).name() << std::endl; // proxy!

	for (auto& e : vi) // ok
	{
	}

//	for (auto& e : vb)  // error. vb 에서 열거하면 proxy 임시객체로 반환
						//      임시객체를 rvalue 이므로 auto& 에 담을수 없습니다
	for (auto&& e : vb) // ok
	{
	}

}
