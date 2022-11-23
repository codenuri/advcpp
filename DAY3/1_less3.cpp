#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	std::sort(v.begin(), v.end(), std::less<int>()); // C++98 ��Ÿ��

	// �Ʒ� �ڵ�� ��� ���� �ǹ� �Դϴ�.
	std::sort(v.begin(), v.end(), std::less<void>()); // C++14 ��Ÿ��
	std::sort(v.begin(), v.end(), std::less<>());
	std::sort(v.begin(), v.end(), std::less()); // C++17
	std::sort(v.begin(), v.end(), std::less{}); //
	std::sort(v.begin(), v.end(), {}); 
}



