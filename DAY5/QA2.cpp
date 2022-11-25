#include <iostream>

struct Int32
{
	int value;
	
	// explicit : 생성자가 변환에 용도로 사용될수 없다.
	explicit Int32(int n) : value(n) {}
};

template<typename T> class vector
{
	T* buff;
public:
	void push_back(const T& a)	// const Int32& a
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

	v.push_back(n1);		// 복사 생성자 호출
	v.emplace_back(n1);		// 복사 생성자 호출

//	v.push_back(10);	// 1. 10 => Int32 임시 객체를 생성
						// 2. 생성된 임시객체를 push_back 에전달
						// 3. new T(임시객체) 할때 복사 생성자 호출
		
	v.emplace_back(10);	// 10 을 emplace_back 에 전달한것!!
						// => 복사 생성자가 아닌
						// => new Int32(10) 으로 생성된것

	// 성능 : emplace_back 이 빠릅니다.
	// 단점 : 변환이 발생하면 위험하다고 생각되는 타입들의 경우
	//		  push_back(인자) 가 에러가 나와도 => 변환 발생후 임식개체생성
	//        emplace_back(인자)는 에러가 아닐수 있습니다. => 생성자 인자로사용

	std::list< std::vector<int> > s;

	s.push_back(10); // error
					// 10 => vector<int> 로 변경해야 하는데..
					// => vector 의 생성자는explicit 입니다.

	s.emplace_back(10); // ok.. vector<int> v(10) 의 의미 이므로
						// vector<int> v(다른vector)

	// 인자 한개인 생성자가 explicit 가 아닌경우 => 무조건 emplace_back  사용!!
	// 인자 한개인 생성자가 explicit 인 경우     => 조심해서 emplace_back 사용하세요
}
