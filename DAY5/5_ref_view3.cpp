#include <vector>
#include <iostream>

// �ٽ� 1. Ŭ�����ȿ� reference ����� ������
// => ���� �����ڿ� ���Կ����ڴ� ���� �˴ϴ�
// => �ʿ��ϸ� ����ڰ� ������ �մϴ�.

template<typename T>
class reverse_view
{
	T& rng;
public:
	reverse_view(T& r) : rng(r) {}
	auto begin() { return rng.rbegin(); }
	auto end() { return rng.rend(); }

	reverse_view& operator=(const reverse_view& other)
	{
		rng = other.rng;	// ������ ���ڵ尡 rng �� ����Ű��
							// vector �� ���� ��� ��.!

		return *this;
	}
};



int main()
{
	std::vector v1 = { 1, 2, 3 };
	std::vector v2 = { 1, 2, 3, 4, 5 };

	reverse_view rv1(v1);
	reverse_view rv2(v2);

	rv1 = rv2;	// ��� �����ؾ� �ұ�� ?
}

