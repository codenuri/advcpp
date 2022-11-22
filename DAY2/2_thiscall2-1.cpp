class Dialog
{
public:
	void Close(int a) {}
	static void Close2(int a) {}
};

void foo(int a) {}

int main()
{
	// �ٽ� 1. ��� �Լ����ּҸ� �������� ��� �Լ� �����͸� ����ؾ��մϴ�
	void(*f1)(int) = &foo;						// �Ϲ��Լ� ������
	void(Dialog::*f2)(int) = &Dialog::Close;	// ��� �Լ� ������

	// �ٽ� 2. ��� �Լ� ������ ����ϱ�
	f1(10); // ok. �Ϲ� �Լ� ������!
//	f2(10); // error. ��� �Լ��� ��ü�� �־�� ȣ�Ⱑ���մϴ�.!!

	Dialog dlg;
//	dlg.f2(10);	// error. Dialog �ȿ��� "f2" ��� ����� ����.!


	// Pointer To member ��� �����ڸ� ����ؾ� �մϴ�.(".*", "->*" )
	dlg.*f2(10);	// error. ������ �켱���� ���� 
					//		  .* ���� () �� �����ϴ�.

	(dlg.*f2)(10);	// ok.. �� ǥ����� ��� �Լ� �����͸� ����ؼ�
					//		��� �Լ��� ȣ���ϴ� ǥ����Դϴ�.

	// .* �� ->* ����ϱ�
	Dialog* pdlg = &dlg;
	(dlg.*f2)(10);
	(pdlg->*f2)(10);	
}






