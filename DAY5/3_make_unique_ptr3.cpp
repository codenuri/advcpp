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
    unique_ptr<Car> p1(new Car);

}

