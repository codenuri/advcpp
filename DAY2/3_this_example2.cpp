// 32 bit

#define USING_GUI
#include "cppmaster.h"
#include <map>

// ec_set_timer �� 2��° ���ڷ� ���޵Ǵ� �Լ���
// �ݵ�� "void(int)" �� ����̾�� �մϴ�.
void foo(int id)
{
	std::cout << "foo : " << id << std::endl;
}

int main()
{
	int id1 = ec_set_timer(1000, foo); // �ð�(ms), �Լ�
	int id2 = ec_set_timer(500, foo); 

	ec_process_message(); 
}
