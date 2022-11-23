#include <iostream>

class RefCount
{
public:
	void Release()
	{
		delete this;
	}
};
class Truck : public RefCount
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};
int main()
{
	Truck* p1 = new Truck;
	p1->Release(); // 
}