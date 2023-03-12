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
		cout << "스택이 가득 찼습니다.." << endl;
}

void Stack::pop()
{
	if (stack_count <= 0)
		cout << "스택이 비었습니다..." << endl;
	else
	{
		p_stack[stack_count--] = 0;
	}
}

void Stack::show_stack()
{
	if (stack_count == 0)
		cout << "스택에 저장된 값이 없습니다.." << endl;
	for (int i = 0; i < stack_count; i++)
		cout << p_stack[i] << " ";
}

//야호
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