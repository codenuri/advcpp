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

}






