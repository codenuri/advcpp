#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <string>

// C��� �Լ��� �����Ǵ� Ÿ�̸� ������ C++ Ŭ�������� ����� ���ô�.
class Clock
{
	std::string name;
public:
	Clock(const std::string& s) : name(s) {}

	void Start(int ms) {}
};

int main()
{
	Clock c1("AAA");
	Clock c2("\tBBB");

	c1.Start(1000);
	c2.Start(500); // 500 ms ���� �ѹ��� �ڽ��� �̸� ���

	ec_process_message();
}