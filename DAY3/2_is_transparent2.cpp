#include <iostream>
#include <string>
#include <set>

struct People
{
	std::string name;
	int age;

	People(const std::string& name, int age) : name(name), age(age) {}
};
// People 자체에 < 연산이 가능하다면 set 에 넣을때 기본 함수 객체인 std::less도
// 가능합니다.
bool operator<(const People& p1, const People& p2) { return p1.name < p2.name;}
bool operator<(const People& p1, const std::string& name) {	return p1.name < name;}
bool operator<(const std::string& name, const People& p2) {	return name < p2.name;}

// 결론 : People 자체는 
// "People 객체 < People 객체"
// "People 객체 < 문자열(이름)"
// "문자열(이름) < People 객체"

int main()
{
	People p1("aaa", 10);
	People p2("bbb", 10);

	std::less<People> f1;
	f1(p1, p2);		// ok
//	f1(p1, "aaa");	// error  people 자체는 p1 < "aaa" 의 능력이 있지만
					// less<People> 의 () 연산자는 같은 타입만 받을수 있다.


//	std::set<People> s;	// std::set<typename Key, typename Pr = less<Key>>
						// std::set<People, std::less<People>> 
						// 즉, 비교 객체가 less<People> 인데..!!!
						// less<People> 은 "People" 만 비교 가능합니다.
	std::set<People, std::less<void>  > s;

	s.emplace("ddd", 20);
	s.emplace("bbb", 30);
	s.emplace("ccc", 40);

	auto ret1 = s.find(People("bbb", 30)); 

	auto ret2 = s.find("bbb"); 
}
