#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <string>

class Clock
{
	static std::map<int, Clock*> this_map; // this �� �����ϴ� �ڷ� ����!

	std::string name;
public:
	Clock(const std::string& s) : name(s) {}

	void Start(int ms)
	{
		int id = ec_set_timer(ms, Handler);

		// �ٽ� : static ��� �Լ����� ����ϱ� ���ؼ�
		//			this �� �ڷᱸ���� �����ϴ� ���!
		this_map[id] = this;
	}

	static void Handler(int id)
	{
		Clock* self = this_map[id];

		std::cout << self->name << std::endl; // 
	}
};
std::map<int, Clock*> Clock::this_map;


int main()
{
	Clock c1("AAA");
	Clock c2("\tBBB");

	c1.Start(1000);
	c2.Start(500); 

	ec_process_message();
}

// static ����Լ��� callback ���޽�
// this �� ����ϴ� ��ǥ�� ���

// 1. callback �Լ� ���ڷ� ����
//   => Thread ���� ����

// 2. this �� �ڷᱸ��(map) �� ����
//  => Clock ����