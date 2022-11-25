#include <iostream>
#include "Car.h"
#include "compressed_pair.h"

// Step 4. unique_ptr �� ũ�⸦ ����ȭ

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
    // �Ʒ� ó�� �ϸ� empty �� "Dx del" �� �޸� ����մϴ�.
    // T* pobj;
    // Dx del;    

    // EBCO �� ���� compressed_pair �� ����ϴ� ���� �����ϴ�.
    compressed_pair<Dx, T*> cp;

public:
    inline explicit unique_ptr(T* p, const Dx& d = Dx())
        : cp( one_and_var, d, p)    // compressed_pair ������ ȣ��
    {}

    inline ~unique_ptr()
    {
        if ( cp.get_second() )
        {
            //del(pobj);
            cp.get_first()( cp.get_second() );
        }
    }

    inline T& operator*()  const { return *cp.get_second(); }
    inline T* operator->() const { return cp.get_second(); }
};

int main()
{
    auto del = [](int* p) { free(p); };

    unique_ptr<int, decltype(del) > p1((int*)malloc(20), del);

    std::cout << sizeof(p1) << std::endl; // ???
}

