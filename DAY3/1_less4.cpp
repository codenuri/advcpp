// 1_less4

// ���ø� ���� <> �� ���� ������ ���

// 1. ����Ʈ �Ķ���ͷ� Ÿ���� ������ ���
template<typename T = void> struct less
{
};
// 2. Ÿ�� �߷��� ������ ���
template<typename T> class vector
{
public:
	vector(int a, const T& value) {}
};
int main()
{
	// C++17 ���ʹ� �Ʒ� ó�� ���ø� ���ڻ����� �����մϴ�.
	less f1;
	vector v(1, 0);
}