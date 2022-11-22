#include <iostream>

class Dialog
{
public:
	void foo() {}
};

class ostream
{
public:
	ostream& operator<<(const char* a) { printf("%s", a); return *this; }
	ostream& operator<<(void*	 a)    { printf("void*  : %p", a); return *this; }
	ostream& operator<<(int		 a)    { printf("int    : %d", a); return *this; }
	ostream& operator<<(double   a)    { printf("double : %f", a); return *this; }
	ostream& operator<<(bool     a)    { printf("bool   : %d", a); return *this; }
};
ostream cout;

int main()
{
	int n = 0;
	double d = 0;

	cout << n << "\n";	// cout.operator<<(int)
	cout << d << "\n";  // cout.operator<<(double)
	cout << &d << "\n"; // cout.operator<<(void*)
	cout << &main << "\n"; // cout.operator<<(void*)

	cout << &Dialog::foo << "\n"; // cout.operator<<( bool ) 을 호출하게 됩니다.
	
//	void* p = reinterpret_cast<void*>(&Dialog::foo);
//	int* p1 = reinterpret_cast<int*>(&Dialog::foo);
//	printf("%d\n", p1[1]);
}


