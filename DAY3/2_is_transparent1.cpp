#include <iostream>
#include <string>
#include <set>

struct People
{
	std::string name;
	int age;

	People(const std::string& name, int age) : name(name), age(age) {}
};

struct PeopleCompare
{
	// 아래 함수는 People , People 만 비교 가능합니다.
	bool operator()(const People& p1, const People& p2) const
	{
		return p1.name < p2.name;
	}
	// People, string(비교의 key값)을 비교
	bool operator()(const People& p, const std::string& name) const
	{
		return p.name < name;
	}
	// string, People 을 비교
	bool operator()(const std::string& name, const People& p) const
	{
		return name < p.name;
	}	

	// 핵심 - C++14 기술
	// => 함수객체를 만들때 되도록이면 "is_transparent" 를 넣자!
	// => 타입을 아무것이나 상관없다.
	// => 함수객체 안에 "is_transparent" 라는 타입이 "있는가 없는가"가 중요
	using is_transparent = int; // typedef int is_transparent;

	// 아래 처럼 해도 됩니다.
//	struct is_transparent {};
};



int main()
{
	// 핵심 1. set 에 사용자 정의 타입을 넣으려면
	//         사용자 정의 타입 객체 2개를 비교할수있는 함수객체가 필요 합니다.
	// std::set<People> s;	// error

	std::set<People, PeopleCompare> s;	// ok


	s.insert(People("xxx", 25)); // People 객체를 만든후에 전달
	s.emplace("aaa", 10);		 // set 이 내부적으로 People 객체를 만들어 달라는것
	s.emplace("ddd", 20);
	s.emplace("bbb", 30);
	s.emplace("ccc", 40);

	// 핵심 2. set 에서 검색 할때..!!
	// 방법 1. People 을 보관하고 있으므로 "People" 객체를 전달해서 검색
	auto ret1 = s.find( People("bbb",30) ); // ok


	// 방법 2. 현재 2개 People 에 대한 비교는 "name" 항목만 사용한다.
	// "이름" 만으로 검색할수 없을까 ?
	auto ret2 = s.find("bbb"); // ??!!!


	// "방법 2" 가 되도록 하려면
	// 1. 비교 함수 객체가 "People객체, std::string" 을 비교 가능해야 합니다.
	// 2. 비교 함수 객체 안에 "using is_transparent = 타입"이 있으면됩니다.
	//    => "타입" 은 아무거나 적으세요.
}
// People 멤버 변수 중에 name 외에 string 변수가 더 있는 경우에도
// s.find("aaa") 처럼 사용할 수 있나요?
// => PeopleCompare 안에서 "People, string" 을 비교할때 name 항목과 비교합니다.

// 원리
// => PeopleCompare 자체는 "People, string" 비교가 가능한 상태 입니다.
// => 그런데, set 을 만들때 아래 처럼 했습니다.

template<typename T, typename Pr>
class set
{
	Pr pr;  // 현재 pr 은 PeopleCompare 입니다.
public:
	iterator find(const T& p) // 이렇게 하면 "People" 만 가능합니다.
	{
		if (pr(root요소, p)) // 비교함수로 검색 시작
		{
			// 결과에 따라 왼쪽 오른쪽으로 이동
		}
	}
	// 비교 함수 객체(PR) 에 is_transparent 가 있을때만 사용하겠다는의미
	// is_transparent가 없으면 아래 함수 템플릿을 사용되지 않습니다.
	// SFINAE
	template<typename K,
			 typename X = Pr::is_transparent> 
	iterator find(const K& p)  // 이렇게 하면 임의의 타입을 받을수 있습니다
	{
		if (pr(root요소, p)) // 비교함수로 검색 시작
		{
			// 결과에 따라 왼쪽 오른쪽으로 이동
		}
	}
};
set<People, PeopleCompare> s;
s.find("문자열전달");