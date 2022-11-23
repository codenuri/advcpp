#include <iostream>
#include <string>
#include <set>

struct People
{
	std::string name;
	int age;

	People(const std::string& name, int age) : name(name), age(age) {}
};
// People ��ü�� < ������ �����ϴٸ� set �� ������ �⺻ �Լ� ��ü�� std::less��
// �����մϴ�.
bool operator<(const People& p1, const People& p2) { return p1.name < p2.name;}
bool operator<(const People& p1, const std::string& name) {	return p1.name < name;}
bool operator<(const std::string& name, const People& p2) {	return name < p2.name;}

// ��� : People ��ü�� 
// "People ��ü < People ��ü"
// "People ��ü < ���ڿ�(�̸�)"
// "���ڿ�(�̸�) < People ��ü"

int main()
{
	People p1("aaa", 10);
	People p2("bbb", 10);

	std::less<People> f1;
	f1(p1, p2);		// ok
//	f1(p1, "aaa");	// error  people ��ü�� p1 < "aaa" �� �ɷ��� ������
					// less<People> �� () �����ڴ� ���� Ÿ�Ը� ������ �ִ�.


//	std::set<People> s;	// std::set<typename Key, typename Pr = less<Key>>
						// std::set<People, std::less<People>> 
						// ��, �� ��ü�� less<People> �ε�..!!!
						// less<People> �� "People" �� �� �����մϴ�.
	std::set<People, std::less<void>  > s;

	s.emplace("ddd", 20);
	s.emplace("bbb", 30);
	s.emplace("ccc", 40);

	auto ret1 = s.find(People("bbb", 30)); 

	auto ret2 = s.find("bbb"); 
}
