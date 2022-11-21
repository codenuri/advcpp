#include <iostream>
#include <vector>

// CRTP ���
// => Curiously Recurring Template Pattern 
// => ��� Ŭ������ ���ø� �ε�, ���ø� ���ڷ� �Ļ� Ŭ�����̸��� ����
//    �ϴ� ���
// => CRTP �� ���� �پ��� Ȱ���� �����ѵ�..
// => �Ʒ� �ڵ�� ���� �Ҹ��ڸ� ������� �ʱ� ���ؼ� ���




template<typename T>
class RefCount
{
	int refCount = 0;
public:
	void AddRef() { ++refCount; }

	void Release()	
	{
		if (--refCount == 0)
			//	delete this;	// ������ : this �� Ÿ���� "RefCount*" ��� ��
			delete static_cast<T*>(this);
	}
protected:
	~RefCount() { std::cout << "~RefCount" << std::endl; }
};


class Truck : public RefCount< Truck  > 
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};
int main()
{
	Truck* p = new Truck();
	p->AddRef();
	p->Release();

}


