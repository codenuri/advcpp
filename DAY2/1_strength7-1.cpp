template<typename T>
class Complex
{
	T real, image;
public:
	Complex(const T& r, const T& i) : real(r), image(i) {}

	// 1. 복사 생성자
	// "Complex<double> c2 = c1" 에서 c1 도 반드시 "Complex<double>" 이어야합니다.
	// 
//	Complex(const Complex& c)    {} // 이 모양은
//	Complex(const Complex<T>& c) {} // 이 모양과 같습니다.

	// 2. Complex<float> 를 인자로!
	// auto c2 = c1; 에서 c2의 타입과 상관없이 c1 은 무조건 Complex<float>만가능
//	Complex(const Complex<float>& c) {}

	
	// 3. Generic (복사)생성자
	// "U(float) 가 T(double)로 복사(대입) 가능하다면
	// "Complex<U> 는 Complex<T> 로 복사(대입)가능해야 한다.
	// Generic 생성자가 필요 하다.!
	// "Coercion by member template" 라는 이름을 가진 기술
	template<typename U>
	Complex(const Complex<U>& c) : real(c.real), image(c.image) {}

	// Complex 끼리는 서로 friend 관계 설정.
	template<typename> friend class Complex;
};

int main()
{
	Complex<float>  c1(3.1f, 2.3f);

	Complex<double> c2 = c1; //	Complex<double> c2(c1);
}