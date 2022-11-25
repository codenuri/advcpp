#include <iostream>
#include <any>	// C++17 ���� �߰�..
// boost ���̺귯���� �ʱ� ���� �ִ� ����.

struct Point
{
	int x, y;

	Point(int a, int b) : x(a), y(b) {}
};

struct any
{
	void* data;

	const std::type_info& (*get_type)(); // �Լ� �������Դϴ�.

	void(*deleter)(void*);	// �����ϴ� ��ü�� �ı��ϱ� ���� �Լ� ������

	template<typename T>
	any(const T& value) : data( new T(value) )
	{
		get_type = []() -> const std::type_info& { return typeid(T); };

		deleter = [](void* data) { delete static_cast<T*>(data); };
	} 

	~any() { deleter( data ); }
};

int main()
{
	Point pt(1, 2);
	any a1 = pt;

	std::cout << a1.get_type().name() << std::endl;


//	Point p = any_cast<Point>(a1);
}

