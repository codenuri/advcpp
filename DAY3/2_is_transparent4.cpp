
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
std::set<People, std::less<void>> s2;

// 방법1 과 방법2의 차이점은 ...
// 결국 "방법2" 는 People 자체에 < 연산이 됩니다.
// => set 에 넣는것 외에도 비교할일이 많이 있다면 당연히 2번이 좋습니다.
People p1, p2;
bool b = p1 < p2; // 방법 2만 가능.

//================
// std::set<int, less<int>> 어떻게 less 만 가지고 가능한가요 ? greater 도있어야
// 하지 않나요 ?
void insert(const T& newelem)
{
	if (pr(root, newelem)) // root < newelem
	{
		// 오른쪽으로 이동
	} 
	else if (pr(newelem, root)) //  newelem < root
	{
		// 왼쪽이동
	}
	else
	{
		// 이미 요소가 있다.
	}

}