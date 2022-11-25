#include <vector>
#include <iostream>

template<typename T> class ref_view
{
	T* pc;
public:
	ref_view(T& c) : pc(&c) {}

	T& base() { return *pc; }
};

// C++20 규칙 : 모든 view 는 view_base 에서 파생되어야 한다.
class view_base {};   // empty class 되어 있습니다.
					// 임의의 타입 "T" 가 view 인지 조사할때
					// view_base 로 부터 파생 되었는지 조사하기 위해
					// 사용됩니다.


// 모든 view 가 가져야 하는 기본 멤버 함수를 제공하는 기반 클래스
template<typename Derived>
class view_interface : public view_base
{
public:
	Derived& cast() { return static_cast<Derived&>(*this); }

	int size() 
	{
		Derived& derv = cast();
		return derv.end() - derv.begin();
	};
	bool empty() { return size() == 0; };
};

template<typename T> 
class reverse_view : public view_interface< reverse_view<T> >
{
	ref_view<T> rng;
public:
	reverse_view(T& r) : rng(r) {}

	auto begin() { return rng.base().rbegin(); }
	auto end() { return rng.base().rend(); }
};

template<typename T> 
class take_view : public view_interface< take_view<T> >
{
	ref_view<T> rng;
	int count;
public:
	take_view(T& r, int cnt) : rng(r), count(cnt) {}

	auto begin() { return rng.base().begin(); }
	auto end() { return std::next(rng.base().begin(), count); }

};

int main()
{
	std::vector v1 = { 1, 2, 3, 4, 5 };

	take_view tv(v1, 3);

	std::cout << v1.size() << std::endl; // 5
	std::cout << tv.size() << std::endl; // 3

}

