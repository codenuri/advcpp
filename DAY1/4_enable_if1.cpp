#include <iostream>

// �ٽ� : foo �Լ��� �Ʒ� ó�� 3���϶�, "foo(3)" �� �Լ� ã�� ����
//       
//template<typename T> 
//void foo(T a)   { std::cout << "T" << std::endl; }

//void foo(int a) { std::cout << "int" << std::endl; }

void foo(...)   { std::cout << "..." << std::endl; }


int main()
{
	foo(3);		// 1. int - exactly matching
				// 2. T - template �� ����ؼ� int ���� ����
				// 3. ... 
}