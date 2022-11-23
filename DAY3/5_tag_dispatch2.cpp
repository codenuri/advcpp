#include <iostream>
#include <mutex>



// ������ �Լ� �����ε��� ���ؼ� empty class Ÿ���� ����
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
    lock_guard<std::mutex> g2(m, adopt_lock);   // �����ڿ��� lock ���� ����.
}

