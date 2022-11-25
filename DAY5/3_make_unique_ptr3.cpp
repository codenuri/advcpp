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
    // ��� 1. 
//  unique_ptr<int, [](int* p) { free(p); } >  p1((int*)malloc(20));
            // error
            // => ����ǥ������ ����� �ӽð�ü �Դϴ�.
            // => ���ø� ���ڷ� Ÿ���� ������ �ϴµ�, ��ü�� ������ ������


    // ��� 2. C++20 ���� ������ ���
//  unique_ptr<int, decltype( [](int* p) { free(p); } ) > p1((int*)malloc(20));
            // => error
            // => ����ǥ������ decltype( ) �ȿ� ������ ����.!!
            // => ��, C++20 ���ʹ� ������ �ֽ��ϴ�.

    // ��� 3. 
    auto del = [](int* p) { free(p); };

    unique_ptr<int, decltype( del ) > p1((int*)malloc(20));
            // => �� �ڵ忡�� ������ ����.
            // => �׷���, ����ǥ������ ����� Ÿ���� ����Ʈ �����ڰ� ����
            // => �׷��� unique_ptr �� �Ҹ��ڿ��� ����!!
            //      Dx d;   <<=== ����Ʈ ������ �ʿ�!!

}

