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
    lock_guard<std::mutex> g1(m1); // �����ڿ��� m1.lock()

    if (m2.try_lock_for(2s)) // lock() �Լ��� �ƴ� 
    {                        // �ٸ� ������� lock �� ȹ��
        // m2 �� ���� lock �� ȹ�������� unlock �� 
        // lock_guard �� �����ϰ� �ʹ�.

//        lock_guard<std::timed_mutex> g2(m2); // ����, m2�� ���ؼ�
                                            // �ٽ� lock �õ�.

        lock_guard<std::timed_mutex> g2(m2, false);
        

    }



}


int main()
{
    foo();
}


