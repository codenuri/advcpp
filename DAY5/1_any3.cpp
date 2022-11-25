
// �ٽ� : ���� ���ø� - C++17

constexpr double pi = 3.14;	// pi �� double Ÿ���Դϴ�.
							// pi �� ����Ҷ��� �̸��� ������ �˴ϴ�.

template<typename T> 
constexpr T pit = static_cast<T>(3.14);  // ���� ���ø�
						 // pit �� ���ø� �Դϴ�.
						 // ����Ϸ��� pit<Ÿ��> ���� �ؾ� �մϴ�.

int main()
{
	double area1 = 3 * 3 * pi;
	double area2 = 3 * 3 * pit<double>;
	float  area3 = 3 * 3 * pit<float>;
}