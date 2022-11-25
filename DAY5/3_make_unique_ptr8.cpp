#include <iostream>
#include "Car.h"
#include "compressed_pair.h"

// Step 6. unique_ptr<int[]> 지원 - C++14 기술


template<typename T>
struct default_delete
{
    constexpr default_delete() noexcept = default;


    template<typename U,
        typename = std::enable_if_t< std::is_convertible_v<U*, T*> >  >
    default_delete(const default_delete<U>&) {}

    inline void operator()(T* obj) const noexcept
    {
        static_assert(sizeof(T) > 0,
            "error, can't delete incomplete type");
        delete obj;
    }
};

template<typename T>
struct default_delete<T[]>
{
    constexpr default_delete() noexcept = default;

    template<typename U,
        typename = std::enable_if_t< std::is_convertible_v<U*, T*> >  >
    default_delete(const default_delete<U>&) {}

    inline void operator()(T* obj) const noexcept
    {
        static_assert(sizeof(T) > 0,
            "error, can't delete incomplete type");
        delete[] obj;
    }
};



template <typename T, typename Dx = default_delete<T> >
class unique_ptr
{
    compressed_pair<Dx, T*> cp; //  <Dx, int[]*> 표기법은 에러 입니다.

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

    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;


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

    template<typename U, typename Dx2>
    unique_ptr(unique_ptr<U, Dx2>&& other) noexcept
        : cp(one_and_var, other.cp.get_first(), other.cp.get_second())
    {
        other.cp.get_second() = nullptr;
    }
 
    template<typename, typename> friend class unique_ptr;
};

// T[] 인 경우를 위한 부분 특수화
template <typename T, typename Dx>
class unique_ptr<T[], Dx>
{
    compressed_pair<Dx, T*> cp; //  <Dx, int[]*> 표기법은 에러 입니다.

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

    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;


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

    template<typename U, typename Dx2>
    unique_ptr(unique_ptr<U, Dx2>&& other) noexcept
        : cp(one_and_var, other.cp.get_first(), other.cp.get_second())
    {
        other.cp.get_second() = nullptr;
    }

    template<typename, typename> friend class unique_ptr;
};

int main()
{
//  unique_ptr<int>   p1(new int);
//  unique_ptr<int>   p2(new int[10]); // 버그, 소멸자에서 delete    사용
//  unique_ptr<int, 삭제자>   p2(new int[10]); // ok
//  unique_ptr<int[]> p3(new int[10]); // ok..  소멸자에서 delete[] 사용
        

    unique_ptr<int>   up1(new int);         // T=int
    unique_ptr<int[]> up2(new int[10]);     // T=int[]
}

