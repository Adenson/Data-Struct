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
	int _top;       // Õ»¶¥
	int _capacity;  // ÈÝÁ¿
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackEnlarge(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType Stacktop(Stack* ps);
bool StackEmpty(Stack* ps);
StackSize(Stack* ps);