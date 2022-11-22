// inline, constexpr

template<typename T> 
[[nodiscard]] const T& max1(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

// C++98 ���� : ġȯ(�������)�� ���� inline ���
template<typename T> 
[[nodiscard]] inline const T& max2(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

// C++11 ���� : constexpr 
// 1. ���ڰ��� ������ �ð��� �˼� �ִٸ� ������ �ð��� ����
// 2. constexpr �� inline �� �ǹ̸� ���� �մϴ�.
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