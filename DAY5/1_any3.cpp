
// 핵심 : 변수 템플릿 - C++17

constexpr double pi = 3.14;	// pi 은 double 타입입니다.
							// pi 를 사용할때는 이름만 적으면 됩니다.

template<typename T> 
constexpr T pit = static_cast<T>(3.14);  // 변수 템플릿
						 // pit 는 템플릿 입니다.
						 // 사용하려면 pit<타입> 으로 해야 합니다.

int main()
{
	double area1 = 3 * 3 * pi;
	double area2 = 3 * 3 * pit<double>;
	float  area3 = 3 * 3 * pit<float>;
}