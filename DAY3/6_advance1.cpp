#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// C++98 시절의 구현 기술

// empty 클래스를 사용해서 반복자의 5가지 종류를 타입화 합니다.

struct input_iterator_tag {};	// 입력 반복자
struct output_iterator_tag {};	// 출력 반복자
struct forward_iterator_tag : input_iterator_tag {}; // 전진형
struct bidirectional_iterator_tag : forward_iterator_tag {}; // 양방향
struct random_access_iterator_tag : bidirectional_iterator_tag  {}; // 임의접근


template<typename T> 
void advance(T& p, int sz)
{
	p = p + sz;
}

int main()
{
	//	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = s.begin();

	xadvance(p, 5); 


	std::cout << *p << std::endl;
}
