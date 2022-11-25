#include <iostream>
#include "Car.h"

// Step 2. 삭제자 변경

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

struct Freer
{
    inline void operator()(void* p) const noexcept
    {
        std::cout << "free" << std::endl;
        free(p);
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
            d(pobj);  // 템플릿 인자로 전달된 함수 객체로 삭제
        }
    }

    inline T& operator*()  const { return *pobj; }
    inline T* operator->() const { return pobj; }
};
int main()
{
    // 아래 처럼 했다면, 삭제자 함수의 주소를 보관할 공간이 필요하게 됩니다.
    // unique_ptr<Car> p1((Car*)std::malloc(sizeof(Car)), &free);

    unique_ptr<Car> p1(new Car); // default_delete 의 operator()로 삭제

    unique_ptr<int, Freer> p2((int*)malloc(100));

}

