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

	void resize(std::size_t newsize, const T& value)
	{
		if (newsize > capacity)	
		{
//			T* temp = static_cast<T*>(operator new(sizeof(T) * newsize));
			T* temp = ax.allocate(newsize);

			for (int i = 0; i < size; i++)
			{
			//	temp[i] = buff[i];	// ������ ȣ���� �ƴ�, ���Կ����� ȣ��

			//	new(&temp[i]) T;			// ����Ʈ ������
			//	new(&temp[i]) T(buff[i]);	// ���� ������

			//	new(&temp[i]) T(std::move(buff[i]));	// �̵� ������

			//	new(&temp[i]) T(std::move_if_noexcept(buff[i]));
								// => move �����ڿ� ���ܰ� ���ٸ� move �����ڻ��
								// => ���� ���ɼ��� ������ ���� ������ ���

				std::allocator_traits<Alloc>::construct(ax,
									&temp[i], std::move_if_noexcept(buff[i]) );
			}
			// ������ �޸� �������� ������ ȣ��
			for (int i = size; i < newsize; i++)
			{
			//	new(&temp[i]) T;			// ����Ʈ ������
			//	new(&temp[i]) T(buff[i]);	// ���� ������

				std::allocator_traits<Alloc>::construct(ax,
								&temp[i], value);
			}
			size = newsize;
			capacity = newsize;
		}
		else
		{
			// �޸� ���Ҵ��� �ʿ� ������
			if (newsize > size)	// ũ�Ⱑ �����Ҷ�
			{
				for (int i = size; i < newsize; i++)
				{
					// ������ ȣ��
					std::allocator_traits<Alloc>::construct(ax,
						&buff[i], value);
				}
				size = newsize;
			}
			else if ( newsize < size) // ũ�� ����
			{
				for (int i = size-1; i >= newsize; i--)
				{
					// �Ҹ��� ȣ��
					std::allocator_traits<Alloc>::destroy(ax, &buff[i]);
				}
				size = newsize;
			}
		}
	}
	// ���� ���� : clear, shink_to_fit() �����غ�����
	//				�Ҹ���ȣ�� ���� ������..!
};
int main()
{
	vector<Point> v(3, Point(0, 0));

	v.resize(5, Point(0,0)); // size �ø���.
}
