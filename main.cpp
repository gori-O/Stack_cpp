#include <iostream>
using namespace std;

class Stack
{
private:
	int stack_size;				
	int stack_count;
	int* p_stack;
public:
	Stack();
	~Stack();
	void create_stack(int size);
	void push(int data);
	void pop();
	void show_stack();
};

Stack::Stack()
{
	stack_size = 0;
	stack_count = 0;
	p_stack = NULL;
}

Stack::~Stack()
{
	if (p_stack != NULL)
		delete p_stack;
}

void Stack::create_stack(int size)
{
	if (p_stack != NULL) delete p_stack;
	stack_size = size;
	p_stack = new int[size];
}

void Stack::push(int data)
{
	if (stack_count < stack_size)
	{
		*(p_stack + stack_count) = data;
		stack_count++;
	}
	else
		cout << "������ ���� á���ϴ�.." << endl;
}

void Stack::pop()
{
	if (stack_count <= 0)
		cout << "������ ������ϴ�..." << endl;
	else
	{
		p_stack[stack_count--] = 0;
	}
}

void Stack::show_stack()
{
	if (stack_count == 0)
		cout << "���ÿ� ����� ���� �����ϴ�.." << endl;
	for (int i = 0; i < stack_count; i++)
		cout << p_stack[i] << " ";
}

//��ȣ
int main()
{
	Stack s;
	s.create_stack(10);
	s.push(10);
	s.push(20);
	s.push(30);
	s.show_stack();

	return 0;
}