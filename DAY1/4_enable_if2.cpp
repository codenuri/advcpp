#include <iostream>

// SFINAE : Substitution Failure Is Not An Error

// 1. �����Ͻ� �Լ� ���ø��� ����ϱ�� �����ߴµ�.

// 2. ���ø����� ���� �Լ��� ����ٰ�(�ν��Ͻ�ȭ) ���� �ߴٸ�

// 3. ������ �ƴϴ�.!! <===~~ �ٽ�!!!

// 4. �����̸��� �ٸ� �Լ��� �ִٸ� ���ȴ�.


template<typename T>
//T foo(T a)  { std::cout << "T" << std::endl; return 0; }
typename T::type foo(T a) { std::cout << "T" << std::endl; return 0; }
// int::type foo(int a) { .... } ����� �Լ��� �����Ϸ��� �մϴ�.

int foo(...) { std::cout << "..." << std::endl; return 0; }


int main()
{
	foo(3); // T ���� ����
}