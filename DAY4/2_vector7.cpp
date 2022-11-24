// 5-2 번 복사하세요
#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

// policy base design(단위 전략 디자인)
// => 클래스가 사용하는 정책을 템플릿 인자로 변경할수 있게 하는 기술

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
		// 앞에 소스 참고 하세요
	}

	T& operator[](int idx) { return buff[idx]; }
};

// vector<bool> 에 대한 부분 특수화
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

		// buff 주소에 sz 개의 비트를 value 로 채우는 코드..
	}

	~vector(){	}

	// Bit 단위로 관리하는 역활을 하는 Proxy 객체
	class BitProxy
	{
		int* buff;
		int idx;
	public:
		BitProxy(int* p, int n) : buff(p), idx(n) {}

		BitProxy& operator=(bool value)
		{
			printf("BitProxy operator=\n");

			// buff 주소의 메모리의 idx 번째 비트를 value로 변경하는
			// 코드 작성
			
			return *this;
		}
		// bool b = v[0] 처럼 사용할수 있게 하기위해
		// BitProxy 를 bool 로 변환되게 합니다.
		operator bool()
		{
			printf("BitProxy operator bool()\n");

			// buff 메모리의 idx 번째 bit 가 0인지 1인지 조사해서 반환하세요
			return true;
		}
	};
	BitProxy operator[](int idx) { return BitProxy(buff, idx); }
};
int main()
{
	vector<bool> v1(100, 0);

	v1[0] = true;	// v1.operator[](0) = true;
					// BitProxy임시객체 = true;
					// BitProxy.operator=(bool) 가 호출됩니다.

	bool b = v1[0]; // bool b = BitProxy임시객체
					// bool b = 임시객체.operator bool()
}
