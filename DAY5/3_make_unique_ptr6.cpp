#include <iostream>
#include "Car.h"
#include "compressed_pair.h"

// Step  5. 복사 금지, 이동 가능

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

    compressed_pair<Dx, T*> cp;

public:
    inline explicit unique_ptr(T* p, const Dx& d = Dx())
        : cp(one_and_var, d, p)  
    {}

    inline ~unique_ptr()
    {
        if (cp.get_second())
        {
            cp.get_first()(cp.get_second());
        }
    }
    inline T& operator*()  const { return *cp.get_second(); }
    inline T* operator->() const { return cp.get_second(); }

    // 복사 생성자와 대입연산자를 삭제
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    // move 생성자 지원
    unique_ptr(unique_ptr&& other) noexcept : cp(std::move(other.cp)) 
    {
        other.cp.get_second() = nullptr;
    }

    unique_ptr& operator=(unique_ptr&& other) noexcept
    {
        if (&other == this) return *this;

        cp = std::move(other.cp);
        other.cp.get_second() = nullptr;

        return *this;
    }



};

int main()
{
    unique_ptr<int> p1(new int);
//    unique_ptr<int> p2 = p1;            // error
    unique_ptr<int> p3 = std::move(p1); // ok 
}

