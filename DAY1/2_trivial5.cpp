#define _ENABLE_ATOMIC_ALIGNMENT_FIX
#include <iostream>
#include <thread>
#include <atomic>

struct Point
{
	int x;
	int y;
//	int z;

	Point() = default;
	Point(const Point& pt) : x(pt.x), y(pt.y) {} 
};

// 핵심 : 복사 생성자가 trivial 하지 않은 타입에 대한 atomic 사용!!
std::atomic<Point> pt;

int main()
{
	Point p = pt.load(); // 스레드에 안전하게 복사!

	std::cout << pt.is_lock_free() << std::endl; // ???
}
