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
};

class Animal {};
class Dog : public Animal {};

int main()
{
    unique_ptr<Dog> up1(new Dog);
    unique_ptr<Animal> up2 = std::move(up1); // 되야 하나요 ?
                                            // 안되야 하나요 ?
}

