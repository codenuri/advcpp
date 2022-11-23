#include <iostream>
#include <mutex>

// 생성자 함수 오버로딩을 위해서 empty class 타입을 설계
// => 컴파일러가 만드는 "디폴트 생성자는 explicit" 가 아닙니다.
// => 디폴트 생성자를 explicit 로 하려면 사용자가 명시적으로 만들어야 합니다.

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
    //  lock_guard<std::mutex> g2(m, adopt_lock);   // 생성자에서 lock 수행 안함.
 
    lock_guard<std::mutex> g2(m, {});   // 되는게 좋은세요 ? 안되는게 좋을까요?
   

    // 이미 C++ 표준에 lock_guard, adopt_lock 모두 있습니다.
    std::lock_guard<std::mutex> g3(m, std::adopt_lock);
}

