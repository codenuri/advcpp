#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <string>

// C언어 함수로 제공되는 타이머 개념을 C++ 클래스에서 사용해 봅시다.
class Clock
{
	std::string name;
public:
	Clock(const std::string& s) : name(s) {}

	void Start(int ms) 
	{
		int id = ec_set_timer(ms, Handler);
	}
	// 1. C언어에서 사용하는 "Callback 함수" 를 객체지향으로 설계할때는
	//    반드시 static 멤버 함수 이어야 합니다.
	static void Handler(int id )
	{
//		std::cout << name << std::endl; // error. "this->name" 이 되어야 하는데
										// this가 없습니다.
	}
};

int main()
{
	Clock c1("AAA");
	Clock c2("\tBBB");

	c1.Start(1000);
	c2.Start(500); // 500 ms 마다 한번씩 자신의 이름 출력

	ec_process_message();
}