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
	// 2. 
}