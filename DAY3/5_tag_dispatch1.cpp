#include <iostream>
#include <mutex>

template <typename Mutex> class lock_guard 
{ 
    Mutex& mtx;
public:
    explicit lock_guard(Mutex& mtx)  : mtx(mtx) { mtx.lock();}
    ~lock_guard() noexcept                      { mtx.unlock(); }
};
std::mutex m;

void foo()
{
    // 동기화 자원의 관리는 직접 하지 말고 lock_guard를 사용해라!!
    lock_guard<std::mutex> g(m);
//  m.lock();
//  m.unlock();
}

int main()
{
    foo();
}


