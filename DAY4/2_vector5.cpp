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

	vector(int sz, const T& value = T()) : size(sz), capacity(sz)
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

	void resize(std::size_t newsize, const T& value = T())
	{
		// �տ� �ҽ� ���� �ϼ���
	}

	T& operator[](int idx) { return buff[idx]; }
};

// �ٽ� : vector<bool> �� ������ ������ �����ؾ� �մϴ�.

int main()
{
	vector<int>  v1(100, 0);	// sizeof(int)*100 �޸� �Ҵ�
	vector<bool> v2(100, 0);	// sizeof(bool)*100 �� �Ҵ�???
								// => sizeof(int)*4�̸� ���� ������� ?
}
