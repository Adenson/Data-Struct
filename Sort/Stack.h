#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <malloc.h>
#include <stdbool.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* _array;
	int _top;       // 栈顶
	int _capacity;  // 容量
}Stack;
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_top = 0;
	ps->_capacity = 6;
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

void StackPush(Stack* ps, STDataType x)
{
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
		return;
	}
	--ps->_top;
}
STDataType Stacktop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return;
	}
	return ps->_array[ps->_top - 1];//此处的ps->_top 需要减 1
}

bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
};