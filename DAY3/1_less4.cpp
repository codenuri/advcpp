#include <vector>

// 템플릿 사용시 <> 를 생략 가능한 경우

// 1. 디폴트 파라미터로 타입을 지정한 경우
template<typename T = void> struct less
{
};
// 2. 생성자로 타입 추론이 가능한 경우
template<typename T> class vector
{
public:
	vector(int a, const T& value) {}
};
int main()
{
	// C++17 부터는 아래 처럼 템플릿 인자생략이 가능합니다.
	less f1;			// 템플릿 인자에 디폴트 타입이 있으므로 생략가능
						// less<void> 의미

	vector v(10, 0);	// 이순간 생성자가 호출되는데, 0 을 보고 T=int로 추론가능
		
	std::vector v1 = { 1,2,3,4,5 }; // 
					// vector(std::initializer_list<T>) 의 생성자 호출됨.
					// 1,2,3,4,5 를 보고 T=int 라는 것을 추론 가능

//	std::vector v2; // error. 추론할 정보가 없습니다. 
}