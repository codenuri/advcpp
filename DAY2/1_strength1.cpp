// 15 page
// [[nodiscard]]
template<typename T>
const T& max1(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}
// [[nodiscard]]: 반환 값을 무시하는 경우 경고를 발생시켜 달라는 "attribute"
//                C++17
template<typename T>
[[nodiscard]] const T& max2(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

int main()
{
	max1(1, 2);	
	max2(1, 2);
}
