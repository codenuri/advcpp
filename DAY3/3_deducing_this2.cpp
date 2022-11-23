#include <iostream>

class Vector
{
	int buff[5] = { 1,2,3,4,5 };
public:
	// [] ������ ������ - ��ü�� �迭 ó�� ��밡���ϰ� �Ҷ� ����� �˴ϴ�.
	// => �� �Լ��� ���鶧�� �Ʒ� ó�� �׻� 2�� ������ �����ϰ� �˴ϴ�.
	int& operator[](int idx) { return buff[idx]; }
	const int& operator[](int idx) const { return buff[idx]; }

	// �̿ܿ��� .begin(), .end() ���� �Լ��� �׻� "����Լ�", "�����Լ�"
	// ������ 2�� ������ �մϴ�.

	// C++23 ���ʹ� "forwarding reference"�� deducing this �� �ذ��մϴ�.
	template<typename T>
	decltype(auto) operator[](this T&& self, int idx)
	{
		return buff[idx];
	}
};

int main()
{
	int n1;

	Vector v1;
	v1[0] = 10;  // T&& => Vector& �Դϴ�.
	n1 = v1[0];

	const Vector v2; // ��� vector
//	v2[0] = 10;		 // error ���;� �մϴ�.
	n1 = v2[0];		 // �Ǿ� �մϴ�. v2.operator[](0) �ε� v2�� �����ü�̹Ƿ�
					 // operator[] �� ��� �Լ� �̾�� �մϴ�.


					// C++23 ����					// c++23
	int n1 = v1[0]; // operator[](0) ȣ��			// operator[](v1)
	int n2 = v2[0]; // operator[](0) const ȣ��		// operator[](v2)
}