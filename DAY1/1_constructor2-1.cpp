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

class PipeStream : public Stream
{
	Buffer buff{ 1024 };
public:
	PipeStream() : Stream(buff) {}
};

// �� �ڵ�� �ᱹ �Ʒ� �ڵ�� �����ϴ�.
/*
class PipeStream : public Stream
{
	Buffer buff;
public:
	PipeStream() : Stream(buff), buff{ 1024 } {}
};
*/

int main()
{
	PipeStream ps;
}
