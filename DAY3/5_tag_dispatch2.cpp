#include <iostream>
#include <mutex>



// 생성자 함수 오버로딩을 위해서 empty class 타입을 설계
struct adopt_lock_t {};

adopt_lock_t adopt_lock;

template <typename Mutex> class lock_guard
{
    Mutex& mtx;
public:
    explicit lock_guard(Mutex& mtx) : mtx(mtx) { mtx.lock(); }

    explicit lock_guard(Mutex& mtx, adopt_lock_t ) : mtx(mtx) { }

    ~lock_guard() noexcept { mtx.unlock(); }
};

int main()
{
    std::mutex m;

    lock_guard<std::mutex> g1(m);               // m.lock()
    lock_guard<std::mutex> g2(m, adopt_lock);   // 생성자에서 lock 수행 안함.
}

