#define USING_GUI
#include <iostream>
#include "cppmaster.h"
#include <map>

// 라이브러리 내부 클래스
class Window
{
	static std::map<int, Window*> this_map;

	int handle; // 윈도우 번호 보관
public:
	// 여기에 코드 완성해 보세요( Create(), Handler() )
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





// 라이브러리 사용자 코드
class MyWindow : public Window
{
public:
	virtual void OnLButtonDown() { std::cout << "LBUTTON" << std::endl; }
};
int main()
{
	MyWindow w;
	w.Create(); // 윈도우가 생성되어야 합니다.
				// 왼쪽 버튼 누르면 "LBUTTON" 나와야 합니다. - 위 가상함수 호출
	ec_process_message();
}
// 위 코드가 "MFC", "QT", "wxWidget" 등 안드로이드 이전에 사용되는 C++ GUI 라이브러리
// 내부에서 공통적으로 사용되던 코드 입니다.