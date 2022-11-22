template<typename T>
class Complex
{
	T real, image;
public:
	Complex(const T& r, const T& i) : real(r), image(i) {}

	// 1. ���� ������
	// "Complex<double> c2 = c1" ���� c1 �� �ݵ�� "Complex<double>" �̾���մϴ�.
	// 
//	Complex(const Complex& c)    {} // �� �����
//	Complex(const Complex<T>& c) {} // �� ���� �����ϴ�.

	// 2. Complex<float> �� ���ڷ�!
	// auto c2 = c1; ���� c2�� Ÿ�԰� ������� c1 �� ������ Complex<float>������
//	Complex(const Complex<float>& c) {}

	
	// 3. Generic (����)������
	// "U(float) �� T(double)�� ����(����) �����ϴٸ�
	// "Complex<U> �� Complex<T> �� ����(����)�����ؾ� �Ѵ�.
	// Generic �����ڰ� �ʿ� �ϴ�.!
	// "Coercion by member template" ��� �̸��� ���� ���
	template<typename U>
	Complex(const Complex<U>& c) : real(c.real), image(c.image) {}

	// Complex ������ ���� friend ���� ����.
	template<typename> friend class Complex;
};

int main()
{
	Complex<float>  c1(3.1f, 2.3f);

	Complex<double> c2 = c1; //	Complex<double> c2(c1);
}