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
// Stream ���� ���� �ʱ�ȭ �ϰ� ���� ����Ÿ�� ��� ����
// ������ Ŭ������ �����մϴ�.
class PipeBuffer
{
protected:
	Buffer buff{ 1024 };
};

class PipeStream : public PipeBuffer, public Stream
{
public:
	PipeStream() : Stream(buff) {}
};


int main()
{
	PipeStream ps;
}
