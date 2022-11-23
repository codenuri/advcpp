#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// C++98 시절의 구현 기술

// empty 클래스를 사용해서 반복자의 5가지 종류를 타입화 합니다.
/*
struct input_iterator_tag {};	// 입력 반복자
struct output_iterator_tag {};	// 출력 반복자
struct forward_iterator_tag       : input_iterator_tag {}; // 전진형
struct bidirectional_iterator_tag : forward_iterator_tag {}; // 양방향
struct random_access_iterator_tag : bidirectional_iterator_tag  {}; // 임의접근

// 이제 각 컨테이너의 반복자를 만드는 사람은 반드시 자신이 어떤 종류인지를
// 약속된 방법으로 알려야 합니다.
template<typename T> class vector_iterator
{
public:
	using iterator_category = random_access_iterator_tag;
};

template<typename T> class list_iterator
{
public:
	using iterator_category = bidirectional_iterator_tag;

	//..... 다양한 반복자 관련 멤버 함수들
};
*/

template<typename T>
void xadvance_imp(T& p, int sz, std::random_access_iterator_tag )
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
	// 반복자의 종류에 따라 함수 오버로딩합니다.
	// => 결국 반복자 안에 "자신이 어떤 종류인지를 나타내는 타입(값이아닌)을 넣고!
	// => 함수 오버로딩 기술로 다른 구현을 사용
	xadvance_imp(p, sz, typename T::iterator_category() );
}


int main()
{
	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	//std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = s.begin();

	xadvance(p, 5); 


	std::cout << *p << std::endl;
}
