#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v(10, 3);

	v.resize(7);  // 이 순간의 원리를 생각해 봅시다.
				  // size 멤버 변수만 변경되고 실제 버퍼 메모리가
				  // 줄어드는 것은 아닙니다.
	
	std::cout << v.size()	  << std::endl;	// 7
	std::cout << v.capacity() << std::endl;	// 10

	v.push_back(0); // 끝에 한개 추가

	std::cout << v.size() << std::endl;	    // 8
	std::cout << v.capacity() << std::endl;	// 10

	v.resize(9);

	std::cout << v.size() << std::endl;	    // 9
	std::cout << v.capacity() << std::endl;	// 10

	v.shrink_to_fit(); // 필요없는 여분의 메모리는 제거해 달라.
						// 1. size(9) 크기의 메모리를 할당후에
						// 2. 기존 버퍼의 내용을 복사하는 원리

	std::cout << v.size() << std::endl;	    // 9
	std::cout << v.capacity() << std::endl;	// 9
}




