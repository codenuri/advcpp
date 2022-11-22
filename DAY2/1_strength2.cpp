// inline, constexpr

template<typename T> 
[[nodiscard]] const T& max1(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

// C++98 시절 : 치환(성능향상)을 위해 inline 사용
template<typename T> 
[[nodiscard]] inline const T& max2(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

// C++11 이후 : constexpr 
// 1. 인자값을 컴파일 시간에 알수 있다면 컴파일 시간에 연산
// 2. constexpr 은 inline 의 의미를 포함 합니다.
template<typename T> 
[[nodiscard]] constexpr const T& max3(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

int main()
{
	int ret1 = max1(1, 2); 
	int ret2 = max2(1, 2); 
	int ret3 = max3(1, 2); 
}