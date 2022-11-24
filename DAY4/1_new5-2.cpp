#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:

	vector(int sz, const T& value) : size(sz), capacity(sz)
	{
		buff = static_cast<T*>(operator new(sizeof(T) * sz));

		int cnt = 0;
		try
		{
			for (int i = 0; i < sz; i++)
			{
				new(&buff[i]) T(value);
				cnt = i;
			}
		}
		catch (...)
		{
			for (int i = 0; i <= cnt; i++)
				buff[i].~T();

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