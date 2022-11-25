#include <iostream>
#include "Car.h"

// Step 2. ������ ����

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
            d(pobj);  // ���ø� ���ڷ� ���޵� �Լ� ��ü�� ����
        }
    }

    inline T& operator*()  const { return *pobj; }
    inline T* operator->() const { return pobj; }
};
int main()
{
    // �Ʒ� ó�� �ߴٸ�, ������ �Լ��� �ּҸ� ������ ������ �ʿ��ϰ� �˴ϴ�.
    // unique_ptr<Car> p1((Car*)std::malloc(sizeof(Car)), &free);

    unique_ptr<Car> p1(new Car); // default_delete �� operator()�� ����

    unique_ptr<int, Freer> p2((int*)malloc(100));

}

