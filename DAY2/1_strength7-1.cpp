template<typename T>
class Complex
{
	T real, image;
public:
	Complex(const T& r, const T& i) : real(r), image(i) {}

	// 복사 생성자의 모양
//	Complex(const Complex& c)    {} // 이 모양은
//	Complex(const Complex<T>& c) {} // 이 모양과 같습니다.


};

int main()
{
	Complex<float>  c1(3.1f, 2.3f);

	Complex<double> c3 = c1; //	Complex<double> c3(c1);
}