#include <vector>

// ���ø� ���� <> �� ���� ������ ���

// 1. ����Ʈ �Ķ���ͷ� Ÿ���� ������ ���
template<typename T = void> struct less
{
};
// 2. �����ڷ� Ÿ�� �߷��� ������ ���
template<typename T> class vector
{
public:
	vector(int a, const T& value) {}
};
int main()
{
	// C++17 ���ʹ� �Ʒ� ó�� ���ø� ���ڻ����� �����մϴ�.
	less f1;			// ���ø� ���ڿ� ����Ʈ Ÿ���� �����Ƿ� ��������
						// less<void> �ǹ�

	vector v(10, 0);	// �̼��� �����ڰ� ȣ��Ǵµ�, 0 �� ���� T=int�� �߷а���
		
	std::vector v1 = { 1,2,3,4,5 }; // 
					// vector(std::initializer_list<T>) �� ������ ȣ���.
					// 1,2,3,4,5 �� ���� T=int ��� ���� �߷� ����

//	std::vector v2; // error. �߷��� ������ �����ϴ�. 
}