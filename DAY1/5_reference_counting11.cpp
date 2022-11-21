// 5_reference_counting11
#include <iostream>
#include <memory>

class Truck
{
};

int main()
{
	// 아래 코드의 문제점을 생각해보세요.
	Truck* p1 = new Truck;

	std::shared_ptr<Truck> sp1(p1);
	std::shared_ptr<Truck> sp2(p1);

}