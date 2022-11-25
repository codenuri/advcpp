#include <iostream>

struct Int32
{
	int value;
	Int32(int n) : value(n) {}
};

template<typename T> class vector
{
	T* buff;
public:
	void push_back(const T& a)
	{
		buff = new T(a);
	}
	template<typename ... ARGS>
	void emplace_back(ARGS&& ... args)
	{
		buff = new T(std::forward<ARGS>(args)...);
	}
};
int main()
{
	Int32 n1(10);

	vector<Int32> v;

	v.push_back(n1);
	v.emplace_back(n1);

	v.push_back(10);
	v.emplace_back(10);
}
