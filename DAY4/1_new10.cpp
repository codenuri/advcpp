// 1_new10
#include <vector>
#include <iostream>

int main()
{
	// 핵심 1. 크기를 지정하는 것과 용량(capacity)를 확보하는 것의 차이점
	std::vector<int> v1(1000); // 1000 개 메모리 할당 + 생성자 호출
								// capacity=1000, size=1000
	std::vector<int> v2;
	v2.reserve(1000);	// 1000개 메모리만 할당
						// capacity = 1000, size = 0

	v2.push_back(10);	// 이순간 사용자 타입이면 생성자 호출
						// size=1
	//----------------------------------------------
	// 핵심 2. 복사 생성자의 동작 방식
	std::vector<int> v3(10, 0);
	v3.resize(7);

	std::vector<int> v4 = v3;	// 깊은 복사 
								// 단, capacity 크기 전체가 아닌
								// size 크기의 메모리만 복사!

	std::cout << v3.capacity() << ", " << v3.size() << std::endl; // 10, 7
	std::cout << v4.capacity() << ", " << v4.size() << std::endl; // 7, 7

	// ==============================
	// 핵심 3. swap 멤버 함수 - 버퍼의 교환
	v3.swap(v4); 

	std::cout << v3.capacity() << ", " << v3.size() << std::endl; // 
	std::cout << v4.capacity() << ", " << v4.size() << std::endl; //

	// 핵심 4. 임시객체 생성후 swap 기술 정리 
	// => effective STL 에 소개된 아주 유명한 기술..
	std::vector<int> v5(10);
	v5.resize(5);


	// case 1. 필요없는 capacity 제거하기
	std::vector<int>(v5).swap(v5);
			// => 1. v5를 복사해서 임시객체 생성
			// => 2. v5와 임시객체의 버퍼 교환
			// => 3. 문장의 끝에서 임시객체 파괴, 자신의 버퍼 삭제

	std::cout << v5.capacity() << ", " << v5.size() << std::endl;


	// case 2. 메모리 완전삭제
	// => 임시객체 생성시, 복사 생성자가 아닌 디폴트 생성자 사용
	std::vector<int>().swap(v5);

	
	// 핵심 5. vector 의 메모리를 완전 삭제하려면
	
	std::vector<int> v6(10);
	
	// 방법1. clear, shink_to_fit()
	v6.clear();			// size 를 0으로 하고
	v6.shrink_to_fit();	// capacity 를 size 와 동일하게.


	// 방법 2. 빈 vector 넣기
	v6 = std::vector<int>();


	// 방법 3. 임시객체 swap
	std::vector<int>().swap(v6);
}