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

	v.resize(3);	// 메모리 자체를 줄이지는 않지만
					// 줄어든 2개의 객체를 파괴(소멸자 호출)해야 합니다
					// "메모리 해제 없이 소멸자만 호출하는 기술이 필요합니다."


	v.resize(4);	// 늘어난 한개를 위한 메모리 공간은 이미 있습니다.
					// 하지만 생성자를 다시 호출해서 DB 에 접속해야 합니다.
					// => 이미 존재하는 메모리에 객체를 생성해야 합니다.
					// => "Placement new" 를 사용해야 합니다.
}




