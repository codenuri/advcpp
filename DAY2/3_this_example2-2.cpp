#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <string>

class Clock;

std::map<int, Clock*> this_map; // this 를 보관하는 자료 구조!


class Clock
{
	std::string name;
public:
	Clock(const std::string& s) : name(s) {}

	void Start(int ms)
	{
		int id = ec_set_timer(ms, Handler);

		// 핵심 : static 멤버 함수에서 사용하기 위해서
		//			this 를 자료구조에 보관하는 기술!
		this_map[id] = this;
	}

	static void Handler(int id)
	{
		Clock* self = this_map[id];

		std::cout << self->name << std::endl; // 
	}
};



int main()
{
	Clock c1("AAA");
	Clock c2("\tBBB");

	c1.Start(1000);
	c2.Start(500); 

	ec_process_message();
}