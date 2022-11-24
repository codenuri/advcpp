#include <vector>
#include <bitset>
#include <iostream>

int main()
{
	// vector<bool> : ũ�⸦ ������ ���ڷ� ����, �����Ҵ�� �޸𸮷� ����
	// bitset       : ũ�⸦ template ���ڷ� ����, ���ø޸� ���

	std::vector<bool> v1(10);	// vector<bool> ����
	std::vector<bool> v2(100);	

	std::bitset<10>  b1;		// bitset �� �����ϴ�
	std::bitset<100> b2;	

	std::cout << sizeof(v1) << std::endl;
	std::cout << sizeof(v2) << std::endl;
	std::cout << sizeof(b1) << std::endl;
	std::cout << sizeof(b2) << std::endl;

	auto ret = b1[0];

	std::cout << typeid(ret).name() << std::endl;
	
	// bitset �� �ݺ��ڰ� �����ϴ�.
	// for( auto e : b1) {} �ȵ˴ϴ�.!!
}



/*
// bitset ����
template<std::size_t sz>
class bitset
{
	// ���ø� ���ڴ� ������ �ð��� �˼� �ֽ��ϴ�.
	// => ���� �迭�� ũ��� ���ɼ� �ֽ��ϴ�.
	int buff[ (sz / 32) + 1 ];
};
*/