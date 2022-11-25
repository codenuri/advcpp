#include <new>      
#include <cstdio>   
#include <stdlib.h>


// 핵심 1. "operator new", "operator delete" 를 사용자가
//         override 할수 있습니다.

void* operator new (std::size_t size) 
{
    printf("operator new (std::size_t size)\n");
    return malloc(size);
}

// 배열 버전이 없으면 위 버전을 사용합니다.
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

void operator delete[] (void* p) noexcept
{
    printf("operator delete[] (void* p)\n");
    std::free(p);
}

int main()
{
    void* p1 = operator new(10);
    operator delete(p1);

    printf("----------------------------------\n");
    
    int* p2 = new int;
    delete p2;

    printf("----------------------------------\n");

    int* p3 = new int[10];
    delete[] p3;
    printf("----------------------------------\n");

}