#include <vector>
#include <bitset>
#include <iostream>

int main()
{
	// vector<bool> : 크기를 생성자 인자로 전달, 동적할당된 메모리로 관리
	// bitset       : 크기를 template 인자로 전달, 스택메모리 사용

	std::vector<bool> v1(10);	// vector<bool> 보다
	std::vector<bool> v2(100);	

	std::bitset<10>  b1;		// bitset 이 좋습니다
	std::bitset<100> b2;	

	std::cout << sizeof(v1) << std::endl;
	std::cout << sizeof(v2) << std::endl;
	std::cout << sizeof(b1) << std::endl;
	std::cout << sizeof(b2) << std::endl;

	auto ret = b1[0];

	std::cout << typeid(ret).name() << std::endl;
	
	// bitset 은 반복자가 없습니다.
	// for( auto e : b1) {} 안됩니다.!!
}



/*
// bitset 원리
template<std::size_t sz>
class bitset
{
	// 템플릿 인자는 컴파일 시간에 알수 있습니다.
	// => 따라서 배열의 크기로 사용될수 있습니다.
	int buff[ (sz / 32) + 1 ];
};
*/