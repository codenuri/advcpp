
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