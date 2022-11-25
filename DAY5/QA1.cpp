#include <new>      
#include <cstdio>   
#include <stdlib.h>
#include <string>

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

void operator delete[](void* p) noexcept
{
    printf("operator delete[] (void* p)\n");
    std::free(p);
}

int main()
{
    // SSO : small string optimization
    //      => 작은 문자열을 힙할당을 하지 않는다는 의미.
    //      => 대부분 "16" 글자를 기준으로 합니다
    // 
//    std::string s1("ABCD");

  std::string s1("ABCDjsdljflsdjflsdjflsdlkds");

}