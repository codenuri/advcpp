#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};
// STL vector �� ���������� ������ ���ô�.
template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz) : size(sz), capacity(sz)
	{
		buff = new T[sz];
		// => �� ǥ����� "T Ÿ���� �ݵ�� ����Ʈ �����ڰ� �־�� �˴ϴ�."

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