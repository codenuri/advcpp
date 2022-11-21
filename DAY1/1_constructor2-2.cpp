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
// 아래 코드는 "C++ 표준 ostream" 을 만들때 나왔던 문제와해결책입니다.
// "Base From Member" 라는 이름을 가진 기술 입니다.
// 구글에서 "C++ IDioms" 라고 검색해보세요 - 1번째 링크 선택
// 
// Stream 보다 먼저 초기화 하고 싶은 데이타를 모아 놓은
// 별도의 클래스를 설계합니다.
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
