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
	std::set<People> s;	// std::set<People, std::less<People>> 


	s.emplace("ddd", 20);
	s.emplace("bbb", 30);
	s.emplace("ccc", 40);

	auto ret1 = s.find(People("bbb", 30)); 

	auto ret2 = s.find("bbb"); 
}
