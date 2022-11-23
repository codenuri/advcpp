#include <iostream>
#include <vector>
#include <list>
#include <iterator>


// 클래스로 만든 반복자와 raw pointer 의 차이점을 해결하기 위한 도구
template<typename T> struct iterator_traits
{
	using iterator_category = typename T::iterator_category;
};

// T= raw pointer 일때 구현을 변경합니다.
template<typename T> struct iterator_traits<T*>
{
	using iterator_category = std::random_access_iterator_tag;
};





template<typename T>
void xadvance_imp(T& p, int sz, std::random_access_iterator_tag)
{
	std::cout << "+ 로 이동" << std::endl;
	p = p + sz;
}
template<typename T>
void xadvance_imp(T& p, int sz, std::input_iterator_tag)
{
	std::cout << "++ 로 이동" << std::endl;
	while (sz--) ++p;
}
template<typename T>
void xadvance(T& p, int sz)
{
	// 아래 코드는 T가 클래스로 만든 반복자만 됩니다.
	// T가 "raw pointer" 라면 에러 입니다.
	// xadvance_imp(p, sz, typename T::iterator_category());

	xadvance_imp(p, sz, typename iterator_traits<T>::iterator_category());
}



int main()
{
	//std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	//std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };
	//auto p = s.begin();

	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = std::begin(x); // 일반함수 begin 사용하면 배열도 가능합니다.
							// 의미는 "auto p = x" 와 같습니다.
							// 즉, p 는 "int*" 타입입니다.
	xadvance(p, 5);	


	std::cout << *p << std::endl;
}
