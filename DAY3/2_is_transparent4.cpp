
// set<People> ���� Ű��(�̸�)�˻��� �����ϰ� �Ϸ���

// ��� 1. People �� ���ϴ� �Լ���ü�� ����� ���
struct PeopleCompare
{
	// People, People �� ���ϴ� operator()
	// People, string �� ���ϴ� operator()
	// string, People �� ���ϴ� operator()

	using is_transparent = int;
};
std::set<People, PeopleCompare> s1;

//-----------------------------------------------
// ��� 2. People Ÿ�Կ�  < �����ڸ� �����ϰ�, less<void> ����
class People
{
	// friend operator<(People, People)
	// friend operator<(People, string)
	// friend operator<(string, People)
};
std::set<People, std::less<void>> s2;

// ���1 �� ���2�� �������� ...
// �ᱹ "���2" �� People ��ü�� < ������ �˴ϴ�.
// => set �� �ִ°� �ܿ��� �������� ���� �ִٸ� �翬�� 2���� �����ϴ�.
People p1, p2;
bool b = p1 < p2; // ��� 2�� ����.

//================
// std::set<int, less<int>> ��� less �� ������ �����Ѱ��� ? greater ���־��
// ���� �ʳ��� ?
void insert(const T& newelem)
{
	if (pr(root, newelem)) // root < newelem
	{
		// ���������� �̵�
	} 
	else if (pr(newelem, root)) //  newelem < root
	{
		// �����̵�
	}
	else
	{
		// �̹� ��Ұ� �ִ�.
	}

}