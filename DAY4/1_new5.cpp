#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};
// STL vector 의 구현원리를 생각해 봅시다.
template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz) : size(sz), capacity(sz)
	{
		buff = new T[sz];
		// => 이 표기법은 "T 타입은 반드시 디폴트 생성자가 있어야 됩니다."

	}
	~vector()
	{
		delete[] buff;
	}
};
int main()
{	
	vector<Point> v(10);
}