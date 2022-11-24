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
		if (newsize > capacity)	// 메모리가 부족할때!!!!
		{
			// 버퍼를 키우기위해 큰 버퍼를 할당할때
			// 절대 아래 처럼 코딩하지 마세요.!!
			// 단점 1. T 타입의 디폴트 생성자가 필요
			// 단점 2. 메모리만 할당하면 되지 객체를 생성할필요없다.!
			//         (생성자 호출할 필요 없다)
			T* tmp = new T[5];

		}
	}
};


int main()
{
	vector<Point> v(3, Point(0, 0));

	v.resize(5); // size 늘리기.
}
