// 32 bit

#define USING_GUI
#include "cppmaster.h"
#include <map>

// ec_set_timer 의 2번째 인자로 전달되는 함수는
// 반드시 "void(int)" 의 모양이어야 합니다.
void foo(int id)
{
	std::cout << "foo : " << id << std::endl;
}

int main()
{
	int id1 = ec_set_timer(1000, foo); // 시간(ms), 함수
	int id2 = ec_set_timer(500, foo); 

	ec_process_message(); 
}
