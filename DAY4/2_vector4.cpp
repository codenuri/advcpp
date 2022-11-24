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

	void resize(std::size_t newsize, const T& value = T() )
	{
		if (newsize > capacity)
		{
			T* temp = ax.allocate(newsize);

			for (int i = 0; i < size; i++)
			{

				std::allocator_traits<Alloc>::construct(ax,
					&temp[i], std::move_if_noexcept(buff[i]));
			}
			for (int i = size; i < newsize; i++)
			{
				std::allocator_traits<Alloc>::construct(ax,
					&temp[i], value);
			}
			size = newsize;
			capacity = newsize;
		}
		else
		{
			if (newsize > size)	
			{
				for (int i = size; i < newsize; i++)
				{

					std::allocator_traits<Alloc>::construct(ax,
						&buff[i], value);
				}
				size = newsize;
			}
			else if (newsize < size) 
			{
				for (int i = size - 1; i >= newsize; i--)
				{					
					std::allocator_traits<Alloc>::destroy(ax, &buff[i]);
				}
				size = newsize;
			}
		}
	}

	// [] ������ ������ : ��ü�� �迭ó�� ����Ҽ� �ְ� �Ѵ�.
	T& operator[](int idx) { return buff[idx]; }
};
int main()
{
	vector<int> v(10, 0);

	v[0] = 10; // v.operator[](10) = 0;

	std::cout << v[0] << std::endl;
}
