#define USING_GUI
#include <iostream>
#include "cppmaster.h"

// 라이브러리 내부 클래스
class Window
{
	int handle; // 윈도우 번호 보관
public:
	// 여기에 코드 완성해 보세요( Create(), Handler() )

	virtual void OnLButtonDown() {}
};
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