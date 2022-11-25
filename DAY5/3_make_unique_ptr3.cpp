#include <iostream>
#include "Car.h"

// Step 3. 삭제자로 람다표현식 지원하기. 

template<typename T>
struct default_delete
{
    inline void operator()(T* obj) const noexcept
    {
        static_assert(sizeof(T) > 0,
            "error, can't delete incomplete type");
        delete obj;
    }
};


template <typename T, typename Dx = default_delete<T> >
class unique_ptr
{
    T* pobj;
public:
    inline explicit unique_ptr(T* p) : pobj(p) {}

    inline ~unique_ptr()
    {
        if (pobj)
        {
            Dx d;
            d(pobj);  
        }
    }

    inline T& operator*()  const { return *pobj; }
    inline T* operator->() const { return pobj; }
};

int main()
{
    // 방법 1. 
//  unique_ptr<int, [](int* p) { free(p); } >  p1((int*)malloc(20));
            // error
            // => 람다표현식의 결과는 임시객체 입니다.
            // => 템플릿 인자로 타입을 보내야 하는데, 객체를 보내기 때문에


    // 방법 2. C++20 부터 가능한 방법
//  unique_ptr<int, decltype( [](int* p) { free(p); } ) > p1((int*)malloc(20));
            // => error
            // => 람다표현식은 decltype( ) 안에 넣을수 없다.!!
            // => 단, C++20 부터는 넣을수 있습니다.

    // 방법 3. 
    auto del = [](int* p) { free(p); };

    unique_ptr<int, decltype( del ) > p1((int*)malloc(20));
            // => 이 코드에는 문제가 없다.
            // => 그런데, 람다표현식이 만드는 타입은 디폴트 생성자가 없다
            // => 그래서 unique_ptr 의 소멸자에서 에러!!
            //      Dx d;   <<=== 디폴트 생성자 필요!!

}

