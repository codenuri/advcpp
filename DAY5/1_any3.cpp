
// �ٽ� : ���� ���ø� - C++17

constexpr double pi = 3.14;	// pi �� double Ÿ���Դϴ�.
							// pi �� ����Ҷ��� �̸��� ������ �˴ϴ�.

template<typename T> 
constexpr T pit = 3.14;  // ���� ���ø�
						 // pit �� ���ø� �Դϴ�.
						 // ����Ϸ��� pit<Ÿ��> ���� �ؾ� �մϴ�.

int main()
{
	double area = 3 * 3 * pi;
}