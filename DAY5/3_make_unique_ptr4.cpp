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
    Dx del;     // 삭제자 객체를 멤버로 포함

public:
    inline explicit unique_ptr(T* p, const Dx& d = Dx()) 
            : pobj(p), del(d)   //  Dx del(d) 이므로 복사 생성자
    {}
    inline ~unique_ptr()
    {
        if (pobj)
        {
            del(pobj);
        }
    }



    inline T& operator*()  const { return *pobj; }
    inline T* operator->() const { return pobj; }
};

int main()
{
    auto del = [](int* p) { free(p); };

    unique_ptr<int, decltype(del) > p1((int*)malloc(20),  del);
}

