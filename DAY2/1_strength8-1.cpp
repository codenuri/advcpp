#include <type_traits>

template<typename T>
class Complex
{
	T real, image;
public:
	Complex(const T& r, const T& i) : real(r), image(i) {}
	// enable_if ����� ����ؼ�
	// "U" �� "T" �� ��ȯ ������ Ÿ���� ��츸 ���ø��� ����ϰ� �մϴ�.

	// => enable_if �� ���� ���� Ÿ�� �ڸ��� ����ϴµ� �����ڴ� ���� Ÿ���� �����ϴ�.
	// => �׷���, �����ڿ����� template ���ڸ� ����ؼ� enable_if ���

	template<typename U,
	         typename X = std::enable_if_t< std::is_convertible_v<U, T> > >

	Complex(const Complex<U>& c)
		: real(c.real), image(c.image) {}

	template<typename> friend class Complex;
};

int main()
{
	Complex<float>  c1(3.1f, 2.3f);
	Complex<double> c2 = c1;

	Complex<const char*> c3("3", "4");
	Complex<double> c4 = c3;	
}