
// set<People> 에서 키값(이름)검색이 가능하게 하려면

// 방법 1. People 을 비교하는 함수객체를 만드는 방법
struct PeopleCompare
{
	// People, People 을 비교하는 operator()
	// People, string 을 비교하는 operator()
	// string, People 을 비교하는 operator()

	using is_transparent = int;
};
std::set<People, PeopleCompare> s1;

//-----------------------------------------------
// 방법 2. People 타입에  < 연산자를 제공하고, less<void> 전달
class People
{
	// friend operator<(People, People)
	// friend operator<(People, string)
	// friend operator<(string, People)
};