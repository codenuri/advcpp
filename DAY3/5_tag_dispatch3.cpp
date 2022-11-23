#include <iostream>
#include <new>


void* operator new(std::size_t sz)
{
	std::cout << "operator new : " << sz << std::endl;

	void* p = malloc(sz);

	if (p == nullptr)
		throw std::bad_alloc();

	return p;
}
// new(std::nonthrow) int[10] 
// => operator new(sizeof(int[10]), std::nonthrow)

struct nothrow_t {};
nothrow_t mynothrow;

void* operator new(std::size_t sz, nothrow_t) noexcept
{
	std::cout << "operator new(nothrow) : " << sz << std::endl;

	void* p = malloc(sz);

	return p; // 실패하면 0반환
}

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
//	int* p2 = new(std::nothrow) int[20]; // 실패시 예외가 아닌 0반환
	int* p2 = new(mynothrow) int[20]; // 실패시 예외가 아닌 0반환

	if (p2 == nullptr) {}
	
	delete[] p2;

}
