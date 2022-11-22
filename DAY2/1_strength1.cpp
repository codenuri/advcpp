// 15 page
// [[nodiscard]]
template<typename T>
const T& max1(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

// attribute : �����Ϸ����� �����ϴ� ��ɹ�
// [[nodiscard]]: ��ȯ ���� �����ϴ� ��� ��� �߻����� �޶�� "attribute"
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
	
	printf("AAA"); // ��ȯ���� ������ ��κ� ������� �ʽ��ϴ�.
				   // ��ȯ���� �߿��� ���� �ƴմϴ�.
}
