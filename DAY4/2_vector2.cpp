// 5-2 �� �����ϼ���
#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

// policy base design(���� ���� ������)
// => Ŭ������ ����ϴ� ��å�� ���ø� ���ڷ� �����Ҽ� �ְ� �ϴ� ���

template<typename T,
	typename Alloc = std::allocator<T> >
class vector
{
	T* buff;
	int size;
	int capacity;

	Alloc ax;
public:

	vector(int sz, const T& value) : size(sz), capacity(sz)
	{
		buff = ax.allocate(sz);

		int cnt = 0;
		try
		{
			for (int i = 0; i < sz; i++)
			{
				std::allocator_traits<Alloc>::construct(ax,
					&buff[i], value);
				cnt = i;
			}
		}
		catch (...)
		{
			for (int i = 0; i <= cnt; i++)
			{
				std::allocator_traits<Alloc>::destroy(ax, &buff[i]);
			}

			ax.deallocate(buff, size);
			size = 0;
			capacity = 0;
		}
	}
	~vector()
	{
		for (int i = 0; i < size; i++)
		{
			std::allocator_traits<Alloc>::destroy(ax, &buff[i]);
		}
		ax.deallocate(buff, size);
		size = 0;
		capacity = 0;
	}

	void resize(std::size_t newsize)
	{
		if (newsize > capacity)	// �޸𸮰� �����Ҷ�!!!!
		{
			// ���۸� Ű������� ū ���۸� �Ҵ��Ҷ�
			// ���� �Ʒ� ó�� �ڵ����� ������.!!
			// ���� 1. T Ÿ���� ����Ʈ �����ڰ� �ʿ�
			// ���� 2. �޸𸮸� �Ҵ��ϸ� ���� ��ü�� �������ʿ����.!
			//         (������ ȣ���� �ʿ� ����)
			T* tmp = new T[5];

		}
	}
};


int main()
{
	vector<Point> v(3, Point(0, 0));

	v.resize(5); // size �ø���.
}
