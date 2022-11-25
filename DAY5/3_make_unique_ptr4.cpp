#include <iostream>
#include "Car.h"

// Step 3. �����ڷ� ����ǥ���� �����ϱ�. 

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
    Dx del;     // ������ ��ü�� ����� ����

public:
    inline explicit unique_ptr(T* p, const Dx& d = Dx()) 
            : pobj(p), del(d)   //  Dx del(d) �̹Ƿ� ���� ������
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

