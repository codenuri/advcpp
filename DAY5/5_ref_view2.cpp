#include <vector>
#include <ranges>
#include <iostream>

// 포인터 처럼 이동가능하지만, 
// -> 가 아닌 . 을 사용할수 있는 이동가능한 참조를 만들어 봅시다.
template<typename T> 
class ref_view
{
	T* pc;
public:
	ref_view(T& c) : pc(&c) {}

	T& base() { return *pc; }
};
int main()
{
	std::vector v1 = { 1, 2, 3 };
	std::vector v2 = { 5, 6, 7, 8, 9 };

//	std::vector<int>& r1 = v1;
//	std::vector<int>& r2 = v2;

	ref_view r1 = v1;
	ref_view r2 = v2;

	r1 = r2; 

	std::cout << v1.size() << std::endl; // 5
	std::cout << v2.size() << std::endl; // 5
	std::cout << r1.base().size() << std::endl; // 5
	std::cout << r2.base().size() << std::endl; // 5


}
