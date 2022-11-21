#include <iostream>

// Base-from-Member

class Buffer
{
	char* buff;
public:
	Buffer(int size) : buff(new char[size])
	{
		std::cout << "버퍼 크기 " << size << "로 초기화" << std::endl;
	}
	void useBuffer() { std::cout << "버퍼 사용" << std::endl; }
};

class Stream
{
public:
	Stream(Buffer& buf) { buf.useBuffer(); }
};
//===========================================
// Stream 보다 먼저 초기화 하고 싶은 데이타를 모아 놓은
// 별도의 클래스를 설계합니다.
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
