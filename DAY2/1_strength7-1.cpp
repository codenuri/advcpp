template<typename T>
class Complex
{
	T real, image;
public:
	Complex(const T& r, const T& i) : real(r), image(i) {}

	// ���� �������� ���
//	Complex(const Complex& c)    {} // �� �����
//	Complex(const Complex<T>& c) {} // �� ���� �����ϴ�.


};

int main()
{
	Complex<float>  c1(3.1f, 2.3f);

	Complex<double> c3 = c1; //	Complex<double> c3(c1);
}