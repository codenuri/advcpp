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

// 핵심 : vector<bool> 은 완전히 구현을 변경해야 합니다.

int main()
{
	vector<int>  v1(100, 0);	// sizeof(int)*100 메모리 할당
	vector<bool> v2(100, 0);	// sizeof(bool)*100 개 할당???
								// => sizeof(int)*4이면 되지 않을까요 ?
}
