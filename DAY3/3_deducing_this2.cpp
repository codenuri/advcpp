#include <iostream>

class Vector
{
	int buff[5] = { 1,2,3,4,5 };
public:
	// [] 연산자 재정의 - 객체를 배열 처럼 사용가능하게 할때 만들게 됩니다.
	// => 이 함수를 만들때는 아래 처럼 항상 2개 버전을 제공하게 됩니다.
	int& operator[](int idx) { return buff[idx]; }
	const int& operator[](int idx) const { return buff[idx]; }

	// 이외에도 .begin(), .end() 같은 함수도 항상 "상수함수", "비상수함수"
	// 버전을 2개 만들어야 합니다.

	// C++23 부터는 "forwarding reference"와 deducing this 로 해결합니다.
	template<typename T>
	decltype(auto) operator[](this T&& self, int idx)
	{
		return buff[idx];
	}
};

int main()
{
	int n1;

	Vector v1;
	v1[0] = 10;  // T&& => Vector& 입니다.
	n1 = v1[0];

	const Vector v2; // 상수 vector
//	v2[0] = 10;		 // error 나와야 합니다.
	n1 = v2[0];		 // 되야 합니다. v2.operator[](0) 인데 v2가 상수객체이므로
					 // operator[] 도 상수 함수 이어야 합니다.


					// C++23 이전					// c++23
	int n1 = v1[0]; // operator[](0) 호출			// operator[](v1)
	int n2 = v2[0]; // operator[](0) const 호출		// operator[](v2)
}