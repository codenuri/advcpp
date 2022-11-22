#include <iostream>
#include <functional>
#include <string>

template<typename T>
const T& mymax(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}
int main()
{
	int ret = mymax(10, 3);	// 3

	std::string s1 = "AAAAA";
	std::string s2 = "BBB";

	auto ret1 = mymax(s1, s2);	
	std::cout << ret1 << std::endl; // "BBB"

	
	// �ٽ� 1. ���ĺ� ������ �ƴ� ���ڿ��� ���̸� �������� ū ���ڿ���
	//        ���ϰ� �ʹ�.
	auto ret2 = mymax(s1.size(), s2.size());
	
	std::cout << ret2 << std::endl;  // 5 �Դϴ�.
									// "AAAAA" �� ������ �Ҽ� �������?


	// �ٽ� 2. ���� ������ ���� �����ϰ� �ͽ��ϴ�.
	// ������ ���� ����� ������ ������

	// ���1. ���� ������ - C++98 ������ STL ��Ÿ��
	mymax(s1, s2,
		[](std::string& a, std::string& b) { return a.size() < b.size(); });


	// ��� 2. ���� ������ ��� - Python ��Ÿ��
	mymax(s1, s2, [](std::string& s) { return a.size(); } );

}