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

// vector<bool> �� ���� �κ� Ư��ȭ
template<typename Alloc >
class vector<bool, Alloc>
{
	int* buff;
	int size;
	int capacity;

//	Alloc ax;	// std::allocator<bool>

	typename std::allocator_traits<Alloc>::template rebind_alloc<int> ax;
				// std::allocator<int>

public:
	vector(int sz, bool value = false) : size(sz), capacity(sz)
	{
		buff = ax.allocate( (sz/32) + 1 );

		// buff �ּҿ� sz ���� ��Ʈ�� value �� ä��� �ڵ�..
	}

	~vector(){	}

	// Bit ������ �����ϴ� ��Ȱ�� �ϴ� Proxy ��ü
	class BitProxy
	{
		int* buff;
		int idx;
	public:
		BitProxy(int* p, int n) : buff(p), idx(n) {}

		BitProxy& operator=(bool value)
		{
			printf("BitProxy operator=\n");

			// buff �ּ��� �޸��� idx ��° ��Ʈ�� value�� �����ϴ�
			// �ڵ� �ۼ�
			
			return *this;
		}
		// bool b = v[0] ó�� ����Ҽ� �ְ� �ϱ�����
		// BitProxy �� bool �� ��ȯ�ǰ� �մϴ�.
		operator bool()
		{
			printf("BitProxy operator bool()\n");

			// buff �޸��� idx ��° bit �� 0���� 1���� �����ؼ� ��ȯ�ϼ���
			return true;
		}
	};
	BitProxy operator[](int idx) { return BitProxy(buff, idx); }
};
int main()
{
	vector<bool> v1(100, 0);

	v1[0] = true;	// v1.operator[](0) = true;
					// BitProxy�ӽð�ü = true;
					// BitProxy.operator=(bool) �� ȣ��˴ϴ�.

	bool b = v1[0]; // bool b = BitProxy�ӽð�ü
					// bool b = �ӽð�ü.operator bool()
}
