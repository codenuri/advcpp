

template<typename T, typename Alloc = std::allocator<T> > 
class vector
{
	T* buff;
	int size;
	int capacity;

	Alloc ax;	// 메모리 할당기 객체
				// vector 의 모든 멤버 함수에서 메모리/할당 해지시
				// 반드시 이 할당기를 사용해야 합니다.
public:
	vector(int sz, const T& value) : size(sz), capacity(sz)
	{
		// 아래 처럼 메모리를 할당하면
		// => 메모리 할당/해지 방법을 교체 할수 없습니다.
		// buff = static_cast<T*>(operator new(sizeof(T) * sz));

		buff = ax.allocate(sz);
	}
	~vector()
	{
		ax.deallocate(buff, sz);
	}
};