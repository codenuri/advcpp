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
    // ����ȭ �ڿ��� ������ ���� ���� ���� lock_guard�� ����ض�!!
    lock_guard<std::mutex> g(m);
//  m.lock();
//  m.unlock();
}

int main()
{
    foo();
}


