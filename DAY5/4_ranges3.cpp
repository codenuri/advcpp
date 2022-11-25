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
	auto end() { return rng.rend(); }
};

template<typename T> 
class take_view
{
	T& rng;
	int count;
public:
	take_view(T& r, int cnt) : rng(r), count(cnt) {}

	auto begin() { return rng.begin(); }
	auto end()   { return std::next(rng.begin(), count) ; }
};

int main()
{
	std::vector v = { 1, 2, 3, 4, 5 };

	take_view tv(v, 3); // v�� 3���� ���� �ִ� view

	// range �� view �� �ڿ��� �������� �����Ƿ�
	// ���� �����̳� ����� view �� ����� �翬�� ����˴ϴ�
	v[0] = 100; 

	for (auto e : tv )
	{
		std::cout << e << std::endl;
	}

}

