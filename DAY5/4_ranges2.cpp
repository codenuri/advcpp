#include <vector>
#include <iostream>

// view : �����̳ʸ� �ٶ� ���� "�ð�"
//		  �ڿ��� �������� ���� "range"

template<typename T> 
class reverse_view
{
	T& rng;
public:
	reverse_view(T& r) : rng(r) {}

	auto begin() { return rng.rbegin(); }
	auto end()   { return rng.rend(); }
};

int main()
{
	std::vector v = { 1, 2, 3, 4, 5 };

//	reverse_view rv(v); // C++17 ���� ���ø� ���� ���������մϴ�.

//	for (auto e : rv )
	for (auto e : reverse_view(v) )
	{
		std::cout << e << std::endl;
	}

}

