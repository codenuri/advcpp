
// 아래 "enable_if" 는 이미 표준에 있습니다.
template<bool, typename T = void > struct enable_if
{
	typedef  T type; // using type = T;
};
template<typename T> struct enable_if<false, T> 
{
	// 핵심 : type 멤버가 없다
};

// enable_if<불값, 타입>::type

int main()
{
	// 아래 코드에서 각 변수의 타입은 ?
	enable_if<true, int>::type  n1; // int n1;
	enable_if<true>::type       n2;	// void n2; 인데 void 는 변수를 만들수 
									//				없으므로 error
	enable_if<false, int>::type n3; // error. "::type" 이 없다.

	// 핵심 정리
	enable_if<true, "타입">::type   : type 은 "타입"
	enable_if<true >::type			: type 은 "void"

	enable_if<false, "타입">::type : error. "::type" 이 없다.
	enable_if<false >::type        : error. "::type" 이 없다.
}




