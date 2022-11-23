// 1_less4

// 템플릿 사용시 <> 를 생략 가능한 경우

// 1. 디폴트 파라미터로 타입을 지정한 경우
template<typename T = void> struct less
{
};
// 2. 타입 추론이 가능한 경우
template<typename T> class vector
{
public:
	vector(int a, const T& value) {}
};
int main()
{
	// C++17 부터는 아래 처럼 템플릿 인자생략이 가능합니다.
	less f1;
	vector v(1, 0);
}