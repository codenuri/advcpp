#include <iostream>

class Label
{
	char* text;
//	int* refcount;
public:
	Label(const char* s)
	{
		text = new char[strlen(s) + 1];
		strcpy_s(text, strlen(s) + 1, s);
	}
	


	/*
	char& operator[](int idx) 
	{
		std::cout << "operator[]" << std::endl;
		return text[idx]; 
	}
	*/
	class CharProxy
	{
		Lable& label;
		int   idx;
	public:
		CharProxy(Lable& b , int n) : label(b), idx(n) {}

		operator char()
		{
			printf("b1[0] �� �캯�� �ִ� ��� - ���纻 �����ʿ� ����\n");
			return label.text[idx];
		}
		CharProxy& operator=(char c)
		{
			printf("b1[0] �� �º��� �ִ� ��� - ���纻 ������ �մϴ�.\n");

			char* temp = new char[strlen(label.text) + 1];
			strcpy_s(temp, strlen(label.text) + 1, label.text);

			label.text = temp;
			label.text[idx] = c;

			return *this;
		}
	};

	friend class CharProxy;

	CharProxy operator[](int idx)
	{
		std::cout << "operator[]" << std::endl;
		return CharProxy(*this, idx);
	}
};

int main()
{
	Label b1("welcome");
	Label b2 = b1;

	char c = b1[0];	// �ӽð�ü.operator char() ȣ���

	b1[0] = 'X';	
}