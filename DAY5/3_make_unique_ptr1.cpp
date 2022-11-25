#include <iostream>
#include "Car.h"

template <typename T> class unique_ptr 
{ 
    T* pobj;
public:
    inline explicit unique_ptr(T* p) : pobj(p) {}

    inline ~unique_ptr()
    {
        if ( pobj )
            delete pobj;
    }

    inline T& operator*()  const { return *pobj; }
    inline T* operator->() const { return pobj; }
};
int main()
{
//  unique_ptr<Car> p1 = new Car; // error
    unique_ptr<Car> p1(new Car);  // ok
    p1->Go();
    (*p1).Go();
}

