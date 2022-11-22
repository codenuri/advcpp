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
	Complex<float>  c2 = c1;	// ok. 복사 생성자 사용
								// => 사용자가 만들지 않으면 컴파일러가
								//	  복사 생성자를 제공!

	Complex<double> c3 = c1;	// 되야 합니다.
								// 그런데, error!!!
								// c3, c1 은 다른 타입입니다.
}