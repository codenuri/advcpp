// noexcept
#include <iostream>

// �Լ��� ���ܰ� ���ٸ�, �����Ϸ����� ���ܰ� ���ٰ� �˷� �ִ� ���� �����ϴ�.
// => ����ȭ�� ������ �ǰ� ( godbolt.org )

// noexcept 1. �Լ� () �ڿ� �ٿ��� ���ܰ� ������ �˸��� ���
void f1() noexcept {}         // ���ܰ� ����
void f1() noexcept(false) {}  // ���ܰ� �ִ�
void f1() noexcept(true)  {}  // ���ܰ� ����

// noexcept 2. "ǥ������ ���ܰ� �ִ��� ������ ����"

bool b1 = noexcept( 3 + 2 );        // true
bool b2 = noexcept( new int[100] ); // false




template<typename T>
[[nodiscard]] constexpr const T& 
max(const T& lhs, const T& rhs) 
{
	return lhs < rhs ? rhs : lhs;
}

int main()
{
	auto ret = max(1, 2);

	std::cout << ret << std::endl;


}