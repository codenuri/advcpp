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

	void resize(std::size_t newsize, const T& value)
	{
		if (newsize > capacity)	
		{
//			T* temp = static_cast<T*>(operator new(sizeof(T) * newsize));
			T* temp = ax.allocate(newsize);

			for (int i = 0; i < size; i++)
			{
			//	temp[i] = buff[i];	// 생성자 호출이 아닌, 대입연산자 호출

			//	new(&temp[i]) T;			// 디폴트 생성자
			//	new(&temp[i]) T(buff[i]);	// 복사 생성자

			//	new(&temp[i]) T(std::move(buff[i]));	// 이동 생성자

			//	new(&temp[i]) T(std::move_if_noexcept(buff[i]));
								// => move 생성자에 예외가 없다면 move 생성자사용
								// => 예외 가능성이 있으면 복사 생성자 사용

				std::allocator_traits<Alloc>::construct(ax,
									&temp[i], std::move_if_noexcept(buff[i]) );
			}
			// 증가된 메모리 영역에도 생성자 호출
			for (int i = size; i < newsize; i++)
			{
			//	new(&temp[i]) T;			// 디폴트 생성자
			//	new(&temp[i]) T(buff[i]);	// 복사 생성자

				std::allocator_traits<Alloc>::construct(ax,
								&temp[i], value);
			}
			size = newsize;
			capacity = newsize;
		}
		else
		{
			// 메모리 재할당이 필요 없을때
			if (newsize > size)	// 크기가 증가할때
			{
				for (int i = size; i < newsize; i++)
				{
					// 생성자 호출
					std::allocator_traits<Alloc>::construct(ax,
						&buff[i], value);
				}
				size = newsize;
			}
			else if ( newsize < size) // 크기 감소
			{
				for (int i = size-1; i >= newsize; i--)
				{
					// 소멸자 호출
					std::allocator_traits<Alloc>::destroy(ax, &buff[i]);
				}
				size = newsize;
			}
		}
	}
	// 도전 과제 : clear, shink_to_fit() 구현해보세요
	//				소멸자호출 잊지 마세요..!
};
int main()
{
	vector<Point> v(3, Point(0, 0));

	v.resize(5, Point(0,0)); // size 늘리기.
}
