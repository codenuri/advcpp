#include <iostream>
#include <thread>
#include <atomic>

//int obj = 0;	// 스레드에 안전하지 않음.

std::atomic<int> obj = 0; // 스레드에 안전합니다.

int main()
{
	++obj; // 멀티스레드에 안전할까요 ?
			// obj.operator++() 호출

	obj.fetch_add(1);	// 이 코드와 동일
						// 1. OS 가 제공하는 동기화 도구를 사용하지 않고
						// 2. CPU 이 명령어로 동기화 됩니다.
						// => "lock-free" 라고 합니다.
			
	std::cout << obj.is_lock_free() << std::endl;
}
