// 5_reference_counting11
#include <iostream>
#include <memory>

class Truck
{
};

int main()
{
	// �Ʒ� �ڵ��� �������� �����غ�����.
	Truck* p1 = new Truck;

	std::shared_ptr<Truck> sp1(p1);
	std::shared_ptr<Truck> sp2(p1);

}