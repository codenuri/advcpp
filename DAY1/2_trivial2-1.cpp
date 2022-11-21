// 2_trivial2-1
#include <iostream>
#include <type_traits>

// POD : Plain Old Data, C언어의 구조체와 호환 되는가 ?
//		 C++98 에 사용되는 용어, C++11 부터는 사용안함.

// C++11 이후
// trivial		   : 특별 함수가 하는일이 널리 알려진 대로 동작하는가 ?
//					 함수 동작에 대한 C와의 호환성
// standard layout : 메모리 구조가 C언어와 호환되는가 ?

struct SL_NOT_TRIVIAL
{
	int x, y;
	SL_NOT_TRIVIAL() {}
};

struct TRIVIAL_NOT_SL
{
	int x;
private:
	int y;
};

struct TRIVIAL_SL
{
	int x;
	int y;

	TRIVIAL_SL() = default;
};

// C++11 이후의 POD = standard layout && trivial 일때 POD 입니다.

int main()
{
	std::cout << std::is_trivially_default_constructible_v<SL_NOT_TRIVIAL> << std::endl;
	std::cout << std::is_standard_layout_v<SL_NOT_TRIVIAL> << std::endl;

	std::cout << std::is_trivially_default_constructible_v<TRIVIAL_NOT_SL> << std::endl;
	std::cout << std::is_standard_layout_v<TRIVIAL_NOT_SL> << std::endl;

	std::cout << std::is_trivially_default_constructible_v<TRIVIAL_SL> << std::endl;
	std::cout << std::is_standard_layout_v<TRIVIAL_SL> << std::endl;

}



