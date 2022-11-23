#include <iostream>
#include <mutex>

// ������ �Լ� �����ε��� ���ؼ� empty class Ÿ���� ����
// => �����Ϸ��� ����� "����Ʈ �����ڴ� explicit" �� �ƴմϴ�.
// => ����Ʈ �����ڸ� explicit �� �Ϸ��� ����ڰ� ��������� ������ �մϴ�.

struct adopt_lock_t { explicit adopt_lock_t() = default; };

constexpr adopt_lock_t adopt_lock;

//============================================================

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

    //  lock_guard<std::mutex> g1(m);               // m.lock()
    //  lock_guard<std::mutex> g2(m, adopt_lock);   // �����ڿ��� lock ���� ����.
 
    lock_guard<std::mutex> g2(m, {});   // �Ǵ°� �������� ? �ȵǴ°� �������?
   

    // �̹� C++ ǥ�ؿ� lock_guard, adopt_lock ��� �ֽ��ϴ�.
    std::lock_guard<std::mutex> g3(m, std::adopt_lock);
}

