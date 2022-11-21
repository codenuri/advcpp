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
// 핵심 1. 멤버 데이타를 기반 클래스 생성자에 보내면 안됩니다.
//        => 초기화되지 않은 데이타를 기반 클래스 생성자가 사용하게 됩니다.
class PipeStream : public Stream
{
	Buffer buff{ 1024 };
public:
	PipeStream() : Stream(buff) {}
};

// 위 코드는 결국 아래 코드와 같습니다.
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
