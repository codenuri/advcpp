#include <vector>
#include <bitset>
#include <iostream>

int main()
{
	std::vector<bool> v1(10);	// vector<bool> 보다
	std::vector<bool> v2(100);	

	std::bitset<10>  b1;		// bitset 이 좋습니다
	std::bitset<100> b2;			
}
