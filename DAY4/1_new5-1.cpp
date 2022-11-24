#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};
// Generic Container IDioms
// => template ��� �����̳� �����
// => ����Ǵ� Ÿ���� ������ �ϴ� �䱸 ������ �ּ�ȭ �Ǿ�� �Ѵ�.
// => "����Ʈ �����ڰ� ���� Ÿ���� ����!!!"
//    ������, "��κ��� Ÿ���� ���� �����ڴ� �ִ�"

// STL �� ����Ǵ� Ÿ���� �䱸����
// 1. ���� �����ڰ� �־�� �Ѵ�.
// 2. �Ҹ��ڰ� �־�� �Ѵ�.

template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz, const T& value) : size(sz), capacity(sz)
	{
		// 1. �޸𸮸� �Ҵ�
		buff = static_cast<T*>(operator new(sizeof(T) * sz));

		// 2. ������ ȣ��
		for (int i = 0; i < sz; i++)
		{
//			new(&buff[i]) T;		// ����Ʈ ������ ȣ��
			new(&buff[i]) T(value);	// ���� ������ ȣ��
		}
	

	}





	~vector()
	{
		delete[] buff;
	}
};


int main()
{
//	vector<Point> v(10); // Point �� ����Ʈ �����ڰ� ������ ����

//	Point pt(0, 0);
//	vector<Point> v(10, pt); // pt�� ����(���������)�ؼ� 10����
							// ������ �ǹ�

	vector<Point> v(10, Point(0, 0));
}