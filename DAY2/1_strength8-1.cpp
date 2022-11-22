#include <type_traits>

template<typename T>
class Complex
{
	T real, image;
public:
	Complex(const T& r, const T& i) : real(r), image(i) {}
	// enable_if 기술을 사용해서
	// "U" 가 "T" 로 변환 가능한 타입인 경우만 템플릿을 사용하게 합니다.

	// => enable_if 는 보통 리턴 타입 자리에 사용하는데 생성자는 리턴 타입이 없습니다.
	// => 그래서, 생성자에서는 template 인자를 사용해서 enable_if 사용

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