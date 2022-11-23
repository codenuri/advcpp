#include <iostream>
#include <new>

int main()
{
	try
	{
		int* p1 = new int[10];  // 실패시 std::bad_alloc 예외 발생
		delete[] p1;
	}
	catch (const std::bad_alloc& e)
	{
	}
	//-------------------------------------------
	int* p2 = new(nothrow) int[20]; // 실패시 예외가 아닌 0반환

	if (p2 == nullptr) {}
	
	delete[] p2;



}
