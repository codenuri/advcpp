#include <iostream>
#include <vector>

class DBConnect
{
public:
	DBConnect() { std::cout << "DBConnect()" << std::endl; }
	~DBConnect() { std::cout << "~DBConnect()" << std::endl; }
};

int main()
{
	std::vector<DBConnect> v(5);

	v.resize(3);	// �޸� ��ü�� �������� ������
					// �پ�� 2���� ��ü�� �ı�(�Ҹ��� ȣ��)�ؾ� �մϴ�
					// "�޸� ���� ���� �Ҹ��ڸ� ȣ���ϴ� ����� �ʿ��մϴ�."


	v.resize(4);	// �þ �Ѱ��� ���� �޸� ������ �̹� �ֽ��ϴ�.
					// ������ �����ڸ� �ٽ� ȣ���ؼ� DB �� �����ؾ� �մϴ�.
					// => �̹� �����ϴ� �޸𸮿� ��ü�� �����ؾ� �մϴ�.
					// => "Placement new" �� ����ؾ� �մϴ�.
}




