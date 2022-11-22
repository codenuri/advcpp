// generic constructor
template<typename T>
class Complex
{
	T real, image;
public:
	Complex(const T& r, const T& i) : real(r), image(i) {}
};

int main()
{
	Complex<float>  c1(3.1f, 2.3f);
	Complex<float>  c2 = c1;	// ok. ���� ������ ���
								// => ����ڰ� ������ ������ �����Ϸ���
								//	  ���� �����ڸ� ����!

	Complex<double> c3 = c1;	// �Ǿ� �մϴ�.
								// �׷���, error!!!
								// c3, c1 �� �ٸ� Ÿ���Դϴ�.
}