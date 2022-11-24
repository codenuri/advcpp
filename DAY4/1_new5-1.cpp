#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};
// Generic Container IDioms
// => template 기반 컨테이너 설계시
// => 저장되는 타입이 가져야 하는 요구 조건은 최소화 되어야 한다.
// => "디폴트 생성자가 없는 타입은 많다!!!"
//    하지만, "대부분의 타입은 복사 생성자는 있다"

// STL 에 저장되는 타입의 요구조건
// 1. 복사 생성자가 있어야 한다.
// 2. 소멸자가 있어야 한다.

template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz, const T& value) : size(sz), capacity(sz)
	{
		// 1. 메모리만 할당
		buff = static_cast<T*>(operator new(sizeof(T) * sz));

		// 2. 생성자 호출
		for (int i = 0; i < sz; i++)
		{
//			new(&buff[i]) T;		// 디폴트 생성자 호출
			new(&buff[i]) T(value);	// 복사 생성자 호출
		}
	

	}





	~vector()
	{
		delete[] buff;
	}
};


int main()
{
//	vector<Point> v(10); // Point 에 디폴트 생성자가 없으면 에러

//	Point pt(0, 0);
//	vector<Point> v(10, pt); // pt를 복사(복사생성자)해서 10개를
							// 만들라는 의미

	vector<Point> v(10, Point(0, 0));
}