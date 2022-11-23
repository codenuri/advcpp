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

	// �ٽ� - C++14 ���
	// => �Լ���ü�� ���鶧 �ǵ����̸� "is_transparent" �� ����!
	// => Ÿ���� �ƹ����̳� �������.
	// => �Լ���ü �ȿ� "is_transparent" ��� Ÿ���� "�ִ°� ���°�"�� �߿�
	using is_transparent = int; // typedef int is_transparent;

	// �Ʒ� ó�� �ص� �˴ϴ�.
//	struct is_transparent {};
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
	// 2. �� �Լ� ��ü �ȿ� "using is_transparent = Ÿ��"�� ������˴ϴ�.
	//    => "Ÿ��" �� �ƹ��ų� ��������.
}
// People ��� ���� �߿� name �ܿ� string ������ �� �ִ� ��쿡��
// s.find("aaa") ó�� ����� �� �ֳ���?
// => PeopleCompare �ȿ��� "People, string" �� ���Ҷ� name �׸�� ���մϴ�.

// ����
// => PeopleCompare ��ü�� "People, string" �񱳰� ������ ���� �Դϴ�.
// => �׷���, set �� ���鶧 �Ʒ� ó�� �߽��ϴ�.

template<typename T, typename Pr>
class set
{
	Pr pr;  // ���� pr �� PeopleCompare �Դϴ�.
public:
	iterator find(const T& p) // �̷��� �ϸ� "People" �� �����մϴ�.
	{
		if (pr(root���, p)) // ���Լ��� �˻� ����
		{
			// ����� ���� ���� ���������� �̵�
		}
	}
	// �� �Լ� ��ü(PR) �� is_transparent �� �������� ����ϰڴٴ��ǹ�
	// is_transparent�� ������ �Ʒ� �Լ� ���ø��� ������ �ʽ��ϴ�.
	// SFINAE
	template<typename K,
			 typename X = Pr::is_transparent> 
	iterator find(const K& p)  // �̷��� �ϸ� ������ Ÿ���� ������ �ֽ��ϴ�
	{
		if (pr(root���, p)) // ���Լ��� �˻� ����
		{
			// ����� ���� ���� ���������� �̵�
		}
	}
};
set<People, PeopleCompare> s;
s.find("���ڿ�����");