// 2_trivial2-1
#include <iostream>
#include <type_traits>

// POD : Plain Old Data, C����� ����ü�� ȣȯ �Ǵ°� ?
//		 C++98 �� ���Ǵ� ���, C++11 ���ʹ� ������.

// C++11 ����
// trivial		   : Ư�� �Լ��� �ϴ����� �θ� �˷��� ��� �����ϴ°� ?
//					 �Լ� ���ۿ� ���� C���� ȣȯ��
// standard layout : �޸� ������ C���� ȣȯ�Ǵ°� ?

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

// C++11 ������ POD = standard layout && trivial �϶� POD �Դϴ�.

int main()
{
	std::cout << std::is_trivially_default_constructible_v<SL_NOT_TRIVIAL> << std::endl;
	std::cout << std::is_standard_layout_v<SL_NOT_TRIVIAL> << std::endl;

	std::cout << std::is_trivially_default_constructible_v<TRIVIAL_NOT_SL> << std::endl;
	std::cout << std::is_standard_layout_v<TRIVIAL_NOT_SL> << std::endl;

	std::cout << std::is_trivially_default_constructible_v<TRIVIAL_SL> << std::endl;
	std::cout << std::is_standard_layout_v<TRIVIAL_SL> << std::endl;

}



