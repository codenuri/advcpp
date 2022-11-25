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
	// �ٽ� 1. ���� �ʱ�ȭ�� ����
	std::unique_ptr<Car> p = new Car; // error.  ���� �ʱ�ȭ
	std::unique_ptr<Car> p(new Car);  // ok	     ���� �ʱ�ȭ

	// �ٽ� 2. -> �� * ������ ������
	p->Go();
	(*p).Go();

	// �ٽ� 3. ����� �ȵ����� move �� ����.
	std::unique_ptr<Car> p1 = p; 
	std::unique_ptr<Car> p2 = std::move(p);

	// �ٽ� 4. ������ ������ ��� ��� �Լ� ����
	Car* cp = p2.get();
	p2.reset();
}