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

// cppreference.com ���� "std::uninitialized_fill" ã�ƺ�����
// => �������� �ڵ� ������

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
			// 1. �޸𸮸� �Ҵ��.. (������ ȣ�� �ȵ� �޸�)
			// 2. buff ~ buff+sz ������ ���ؼ�
			// 3. value �� ä�� �޶�(��������� ȣ��)
			// 4. ���н�, �Ҹ��� �ٽ� ȣ���ϰ�
			// 5. ���ܸ� �߻�
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