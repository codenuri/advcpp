#include <iostream>

// Base-from-Member

class Buffer
{
	char* buff;
public:
	Buffer(int size) : buff(new char[size])
	{
		std::cout << "���� ũ�� " << size << "�� �ʱ�ȭ" << std::endl;
	}
	void useBuffer() { std::cout << "���� ���" << std::endl; }
};

class Stream
{
public:
	Stream(Buffer& buf) { buf.useBuffer(); }
};
//===========================================
// �Ʒ� �ڵ�� "C++ ǥ�� ostream" �� ���鶧 ���Դ� �������ذ�å�Դϴ�.
// "Base From Member" ��� �̸��� ���� ��� �Դϴ�.
// ���ۿ��� "C++ IDioms" ��� �˻��غ����� - 1��° ��ũ ����
// 
// Stream ���� ���� �ʱ�ȭ �ϰ� ���� ����Ÿ�� ��� ����
// ������ Ŭ������ �����մϴ�.
class PipeBuffer
{
protected:
	Buffer buff{ 1024 };
};

class PipeStream : protected PipeBuffer, public Stream
{
public:
	PipeStream() : Stream(buff) {}
};


int main()
{
	PipeStream ps;
}
