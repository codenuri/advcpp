#include <iostream>
#include <string>
#include <optional>
/*
// 방법 1. pair<int, bool> 를 사용하자
std::pair<int, bool> foo()
{
	// 실패를 반환하고 싶다.
//	return std::make_pair(0,   false);
	return std::make_pair(100, true);
}
*/
// C++17 의 std::optional 이 결국 pair<T, bool> 입니다.
std::optional<int> foo()
{
	return 100; // 성공
//	return std::nullopt; // 실패
}

int main()
{
	auto ret = foo();

	if (ret) // 이렇게 조사 가능
	{
		std::cout << *ret << std::endl; // 결과 얻기
	}
	else
	{
		std::cout << "fail" << std::endl;
	}
}

