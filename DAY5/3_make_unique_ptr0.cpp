#include <iostream>
#include <memory>

class Car
{
public:
    ~Car()    { std::cout << "~Car" << std::endl; }
    void Go() { std::cout << "Car Go" << std::endl; }
};
int main()
{
	// 핵심 1. 직접 초기화만 가능
	std::unique_ptr<Car> p = new Car; // error.  복사 초기화
	std::unique_ptr<Car> p(new Car);  // ok	     직접 초기화

	// 핵심 2. -> 와 * 연산자 재정의
	p->Go();
	(*p).Go();

	// 핵심 3. 복사는 안되지만 move 는 가능.
	std::unique_ptr<Car> p1 = p; 
	std::unique_ptr<Car> p2 = std::move(p);

	// 핵심 4. 많지는 않지만 몇개의 멤버 함수 제공
	Car* cp = p2.get();
	p2.reset();
}