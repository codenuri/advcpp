// 4_temporary_proxy2
#include <iostream>

class Label
{
	const char* text;
	int* refcount;
public:
	Label(const char* s)
	{
		text = new char[strlen(s) + 1];
		strcpy_s(text, strlen(s) + 1, s);
	}
};
int main()
{
	Label b1("welcome");
	Label b2 = b1;
}