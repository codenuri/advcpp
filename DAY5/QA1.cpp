#include <new>      
#include <cstdio>   
#include <stdlib.h>
#include <string>

void* operator new (std::size_t size)
{
    printf("operator new (std::size_t size)\n");
    return malloc(size);
}

// �迭 ������ ������ �� ������ ����մϴ�.
void* operator new[](std::size_t size)
{
    printf("operator new[](std::size_t size)\n");
    return malloc(size);
}

//-----------------------------------------------
void operator delete (void* p) noexcept
{
    printf("operator delete (void* p)\n");
    std::free(p);
}

void operator delete (void* p, std::size_t) noexcept
{
    printf("operator delete (void* p, std::size_t)\n");
    std::free(p);
}

void operator delete[](void* p) noexcept
{
    printf("operator delete[] (void* p)\n");
    std::free(p);
}

int main()
{
    std::string s1("ABCD");

}