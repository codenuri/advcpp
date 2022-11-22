template<typename T>
class Complex
{
	T real, image;
public:
	Complex(const T& r, const T& i) : real(r), image(i) {}

	// 아래 코드는 "템플릿 => C++ 코드 생성자" 를 생성한 후에
	// "real(c.real)" <== 이 부분 컴파일시에 에러 입니다.
	template<typename U>
	Complex(const Complex<U>& c) 
		: real(c.real), image(c.image) {}

	template<typename> friend class Complex;
};

int main()
{
	Complex<float>  c1(3.1f, 2.3f);
	Complex<double> c2 = c1; 

	Complex<const char*> c3("3", "4");
	Complex<double> c4 = c3;	// error. 에러 메세지 확인해 보세요
}