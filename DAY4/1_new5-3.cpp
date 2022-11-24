#include <iostream>
#include <memory>	// std::uninitialized_fill
class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

// cppreference.com 에서 "std::uninitialized_fill" 찾아보세요
// => 구현원리 코드 보세요

template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:

	vector(int sz, const T& value) : size(sz), capacity(sz)
	{
		buff = static_cast<T*>(operator new(sizeof(T) * sz));

		try
		{
			// 1. 메모리만 할당된.. (생성자 호출 안된 메모리)
			// 2. buff ~ buff+sz 구간에 대해서
			// 3. value 로 채워 달라(복사생성자 호출)
			// 4. 실패시, 소멸자 다시 호출하고
			// 5. 예외를 발생
			std::uninitialized_fill(buff, buff + sz, value);
		}
		catch (...)
		{
			operator delete(buff);
			size = 0;
			capacity = 0;
		}
	}



	~vector()
	{
		delete[] buff;
	}
};


int main()
{
	vector<Point> v(10, Point(0, 0));
}