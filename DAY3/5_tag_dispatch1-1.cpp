#include <iostream>
#include <mutex>
#include <chrono>
using namespace std::literals;

template <typename Mutex> class lock_guard
{
    Mutex& mtx;
public:

    explicit lock_guard(Mutex& mtx, bool bLock = true) 
        : mtx(mtx) 
    { 
        if ( bLock )
            mtx.lock(); 
    }

    ~lock_guard() noexcept { mtx.unlock(); }
};

std::mutex       m1;
std::timed_mutex m2;

void foo()
{
    lock_guard<std::mutex> g1(m1); // 생성자에서 m1.lock()

    if (m2.try_lock_for(2s)) // lock() 함수가 아닌 
    {                        // 다른 방법으로 lock 을 획득
        // m2 는 직접 lock 을 획득했지만 unlock 은 
        // lock_guard 에 의존하고 싶다.

//        lock_guard<std::timed_mutex> g2(m2); // 버그, m2에 대해서
                                            // 다시 lock 시도.

        lock_guard<std::timed_mutex> g2(m2, false);
        

    }



}


int main()
{
    foo();
}


