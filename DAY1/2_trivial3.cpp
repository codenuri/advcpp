#include <iostream>

struct Point
{
	int x, y;

	Point() = default;
	Point(int a, int b) : x(a), y(b) {}

//	Point(const Point& pt) : x(pt.x), y(pt.y) {}
};

template<typename T>
void copy(T* dst, T* src, std::size_t sz)
{
	if (std::is_trivially_copyable_v<T>)
	{
		std::cout << "using memcpy" << std::endl;
		memcpy(dst, src, sizeof(T) * sz);
	}
	else
	{
		std::cout << "using copy constructor" << std::endl;
		while (sz--)
		{
			new(dst) T(*src); // 복사 생성자 호출 - 수요일 정도에 배웁니다.
			++dst, ++src;
		}
	}
}
int main()
{
	Point pt1[5] = { {1,1}, {2,2}, {3,3}, {4,4}, {5,5} };
	Point pt2[5];
	copy(pt2, pt1, 5);

}
