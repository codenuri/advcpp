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
	// �Ʒ� �Լ��� People , People �� �� �����մϴ�.
	bool operator()(const People& p1, const People& p2) const
	{
		return p1.name < p2.name;
	}
	// People, string(���� key��)�� ��
	bool operator()(const People& p, const std::string& name) const
	{
		return p.name < name;
	}
	// string, People �� ��
	bool operator()(const std::string& name, const People& p) const
	{
		return name < p.name;
	}
};



int main()
{
	// �ٽ� 1. set �� ����� ���� Ÿ���� ��������
	//         ����� ���� Ÿ�� ��ü 2���� ���Ҽ��ִ� �Լ���ü�� �ʿ� �մϴ�.
	// std::set<People> s;	// error

	std::set<People, PeopleCompare> s;	// ok


	s.insert(People("xxx", 25)); // People ��ü�� �����Ŀ� ����
	s.emplace("aaa", 10);		 // set �� ���������� People ��ü�� ����� �޶�°�
	s.emplace("ddd", 20);
	s.emplace("bbb", 30);
	s.emplace("ccc", 40);

	// �ٽ� 2. set ���� �˻� �Ҷ�..!!
	// ��� 1. People �� �����ϰ� �����Ƿ� "People" ��ü�� �����ؼ� �˻�
	auto ret1 = s.find( People("bbb",30) ); // ok

	// ��� 2. ���� 2�� People �� ���� �񱳴� "name" �׸� ����Ѵ�.
	// "�̸�" ������ �˻��Ҽ� ������ ?
	auto ret2 = s.find("bbb"); // ??!!!

	// "��� 2" �� �ǵ��� �Ϸ���
	// 1. �� �Լ� ��ü�� "People��ü, std::string" �� �� �����ؾ� �մϴ�.
	// 2. 
}