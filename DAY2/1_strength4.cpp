// checked_delete
#include <iostream>

struct Object;	// Ŭ����(����ü) ���� ����(forward declaration)
				// "incomplete type(�Ҿ����� Ÿ��)" �̶�� �մϴ�.

//Object obj; // error. ���漱�� �Ǿ� �ִ� Ÿ���� ��ü�� ���� �ȵ�.
	  		  //        ������ ������ �ƴϹǷ� size �� �˼� ����.

//Object* p;  // ok. ������ ������ ����. ������ ������ ũ�Ⱑ ������ �����Ƿ�

// �ٽ� : incomplete type �� delete �ϸ� �Ҹ��ڰ� ȣ����� �ʴ´�.
void deleter(Object* p)
{
	// �Ʒ� ����� "checked delete" ��� �մϴ�.
	static_assert(sizeof(Object) > 0,
							"error, can't delete incomplete type");
	delete p;
}




struct Object
{
	Object()  { std::cout << "Object()" << std::endl; }
	~Object() { std::cout << "~Object()" << std::endl; }
};


int main()
{
	Object* p = new Object();
	deleter(p);
}