#define USING_GUI
#include <iostream>
#include "cppmaster.h"

// ���̺귯�� ���� Ŭ����
class Window
{
	int handle; // ������ ��ȣ ����
public:
	// ���⿡ �ڵ� �ϼ��� ������( Create(), Handler() )

	virtual void OnLButtonDown() {}
};
// ���̺귯�� ����� �ڵ�
class MyWindow : public Window
{
public:
	virtual void OnLButtonDown() { std::cout << "LBUTTON" << std::endl; }
};
int main()
{
	MyWindow w;
	w.Create(); // �����찡 �����Ǿ�� �մϴ�.
				// ���� ��ư ������ "LBUTTON" ���;� �մϴ�. - �� �����Լ� ȣ��
	ec_process_message();
}