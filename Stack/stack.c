#include"stack.h"
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_top = 0;
	ps->_capacity = 4;
	ps->_array = (STDataType*)malloc(sizeof(STDataType)*ps->_capacity);
}
void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_array == NULL)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = ps->_top = 0;
	}
}
void StackEnlarge(Stack* ps)
{
	assert(ps);
	if (ps->_top < ps->_capacity) 
	{
		return;
	}
	else if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = (ps->_capacity) * 2;
		STDataType* newarray = (STDataType*)realloc(ps->_array, sizeof(STDataType)*newcapacity);
		if (newarray == NULL)
		{
			printf("realloc error");
			exit(-1);
		}
		////free(ps->_array);�˴�����Ҫ�ͷţ�realloc ������Զ��ͷ�ԭ����
		ps->_array = NULL;
		ps->_array = newarray;
		ps->_capacity = newcapacity;
	}
}
void StackPush(Stack* ps, STDataType x)
{
	//assert(ps);
	//StackEnlarge(ps);
	//ps->_array[ps->_top] = x;
	//++ps->_top;

	//���߲��õ������ݺ���,�����Ӽ򵥵�
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 2 : ps->_capacity * 2;
		ps->_array = (STDataType*)realloc(ps->_array, sizeof(STDataType)*newcapacity);
		ps->_capacity = newcapacity;
	}
	ps->_array[ps->_top] = x;
	++ps->_top;
}
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return;	}
	--ps->_top;
}
STDataType Stacktop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return;
	}
	return ps->_array[ps->_top-1];//�˴���ps->_top ��Ҫ�� 1
}

bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == NULL ? 0 : 1;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
};