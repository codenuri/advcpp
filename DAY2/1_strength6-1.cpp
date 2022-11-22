
// 인자가 없거나 여러개인 경우도 explicit 붙이는 경우가 많습니다.
struct empty1 {	empty1() = default;};
struct empty2 { explicit empty2() = default; };

struct Point1 {	Point1(int a, int b) {} };
struct Point2 { explicit Point2(int a, int b) {} };

void f1(empty1 e1) {}
void f2(empty2 e2) {}
void f3(Point1 p1) {}
void f4(Point2 p1) {}

int main()
{
	f1({}); // ok
	f2({}); // error. empty2 는 explicit

	f3({ 1,2 }); // ok
	f4({ 1,2 }); // error.
}