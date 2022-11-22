
#include <iostream>

struct identity
{
	// T&& : ��� Ÿ���� ��� ��ü�� �ްڴٴ� �ǹ�
	// return std::forward<T>(obj) : ó�� ���ڷ� ���� ��ü��
	//								��� ��ȭ�� ���� ��ȯ�ϰڴٴ� ��
	template<typename T>
	constexpr T&& operator()(T&& obj) const noexcept
	{
		return std::forward<T>(obj);
	}
};

int main()
{
	identity f;

	int n = 10;

	f(n);	// f �� ����� �ٽ� n �� ��ȯ �մϴ�.
			// => n�� ���� ��� ��ȭ�� ���� ������ ��ü�� ��ȯ �մϴ�.

	std::cout << &n    << std::endl;
	std::cout << &f(n) << std::endl;
	
}