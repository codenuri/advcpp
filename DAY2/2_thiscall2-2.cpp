#include <functional>

class Dialog
{
public:
	void Close(int a) {}
	static void Close2(int a) {}
};

void foo(int a) {}

int main()
{
	void(*f1)(int) = &foo;						
	void(Dialog::*f2)(int) = &Dialog::Close;	

	Dialog dlg;

	// �ٽ� 1. �Ϲ� �Լ� ������ȭ ��� �Լ� �����ʹ� ������ �ٸ��ϴ�.
	f1(10);
	(dlg.*f2)(10);	

	// �ٽ� 2. std::invoke �� ����ϸ� ������ ǥ�������� ����Ҽ� �ֽ��ϴ�.
	// => C++17
	std::invoke(f1, 10);      // �Ϲ��Լ������� ���
	std::invoke(f2, dlg, 10); // ����Լ������� ���


	// �ٽ� 3. std::mem_fn �� ����ϸ� ��� �Լ��� �ּҸ� �����ߴٰ�
	//  ()�� ȣ�Ⱑ���մϴ�. - C++11
	auto f3 = std::mem_fn(&Dialog::Close);

	f3(dlg, 10); 
//	(dlg.*f3)(10); // f3 �� raw pointer ���ٸ� �̷��� �߾�� �մϴ�.

	// ���� : ��� �Լ��� �ּҸ� ���Ҷ��� �ݵ�� &�� �ٿ��� �մϴ�.
	f1 = foo; // �̷����ص� �ǰ�
	f1 = &foo; // �� ǥ�⵵ ����
	f2 = Dialog::Close; // error. & �� �ݵ�� �ʿ� 
	f2 = &Dialog::Close; // ok
}






