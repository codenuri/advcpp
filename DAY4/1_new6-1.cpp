

template<typename T, typename Alloc = std::allocator<T> > 
class vector
{
	T* buff;
	int size;
	int capacity;

	Alloc ax;	// �޸� �Ҵ�� ��ü
				// vector �� ��� ��� �Լ����� �޸�/�Ҵ� ������
				// �ݵ�� �� �Ҵ�⸦ ����ؾ� �մϴ�.
public:
	vector(int sz, const T& value) : size(sz), capacity(sz)
	{
		// �Ʒ� ó�� �޸𸮸� �Ҵ��ϸ�
		// => �޸� �Ҵ�/���� ����� ��ü �Ҽ� �����ϴ�.
		// buff = static_cast<T*>(operator new(sizeof(T) * sz));

		buff = ax.allocate(sz);
	}
	~vector()
	{
		ax.deallocate(buff, sz);
	}
};