#include <iostream>

struct Int32
{
	int value;
	
	// explicit : �����ڰ� ��ȯ�� �뵵�� ���ɼ� ����.
	explicit Int32(int n) : value(n) {}
};

template<typename T> class vector
{
	T* buff;
public:
	void push_back(const T& a)	// const Int32& a
	{
		buff = new T(a);	
	}
	template<typename ... ARGS>
	void emplace_back(ARGS&& ... args)
	{
		buff = new T(std::forward<ARGS>(args)...);
	}
};
int main()
{
	Int32 n1(10);

	vector<Int32> v;

	v.push_back(n1);		// ���� ������ ȣ��
	v.emplace_back(n1);		// ���� ������ ȣ��

//	v.push_back(10);	// 1. 10 => Int32 �ӽ� ��ü�� ����
						// 2. ������ �ӽð�ü�� push_back ������
						// 3. new T(�ӽð�ü) �Ҷ� ���� ������ ȣ��
		
	v.emplace_back(10);	// 10 �� emplace_back �� �����Ѱ�!!
						// => ���� �����ڰ� �ƴ�
						// => new Int32(10) ���� �����Ȱ�

	// ���� : emplace_back �� �����ϴ�.
	// ���� : ��ȯ�� �߻��ϸ� �����ϴٰ� �����Ǵ� Ÿ�Ե��� ���
	//		  push_back(����) �� ������ ���͵� => ��ȯ �߻��� �ӽİ�ü����
	//        emplace_back(����)�� ������ �ƴҼ� �ֽ��ϴ�. => ������ ���ڷλ��

	std::list< std::vector<int> > s;

	s.push_back(10); // error
					// 10 => vector<int> �� �����ؾ� �ϴµ�..
					// => vector �� �����ڴ�explicit �Դϴ�.

	s.emplace_back(10); // ok.. vector<int> v(10) �� �ǹ� �̹Ƿ�
						// vector<int> v(�ٸ�vector)

	// ���� �Ѱ��� �����ڰ� explicit �� �ƴѰ�� => ������ emplace_back  ���!!
	// ���� �Ѱ��� �����ڰ� explicit �� ���     => �����ؼ� emplace_back ����ϼ���
}
