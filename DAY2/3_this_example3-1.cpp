#define USING_GUI
#include <iostream>
#include "cppmaster.h"
#include <map>

// ���̺귯�� ���� Ŭ����
class Window
{
	static std::map<int, Window*> this_map;

	int handle; // ������ ��ȣ ����
public:
	// ���⿡ �ڵ� �ϼ��� ������( Create(), Handler() )
	void Create()
	{
		handle = ec_make_window(&Handler, "A");

		this_map[handle] = this;
	}

	static int Handler(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN: self->OnLButtonDown(); break;
		case WM_KEYDOWN: break;
		}
		return 0;
	}

	virtual void OnLButtonDown() {}
};
std::map<int, Window*> Window::this_map;





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
// �� �ڵ尡 "MFC", "QT", "wxWidget" �� �ȵ���̵� ������ ���Ǵ� C++ GUI ���̺귯��
// ���ο��� ���������� ���Ǵ� �ڵ� �Դϴ�.