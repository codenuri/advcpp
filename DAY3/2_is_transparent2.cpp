#include <iostream>
#include <string>
#include <set>

struct People
{
	std::string name;
	int age;

	People(const std::string& name, int age) : name(name), age(age) {}
};


int main()
{
	std::set<People> s;	

	s.emplace("ddd", 20);
	s.emplace("bbb", 30);
	s.emplace("ccc", 40);

	auto ret1 = s.find(People("bbb", 30)); 

	auto ret2 = s.find("bbb"); 
}
