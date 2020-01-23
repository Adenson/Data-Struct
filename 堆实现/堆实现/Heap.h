#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef int HpDataType;
typedef struct Heap
{ 
	HpDataType* _a;
	int _size;    
	int _capacity; 
}Heap;
void HeapInit(Heap* hp, HpDataType* a, int n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HpDataType x);
void HeapPop(Heap* hp);
HpDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);

void AdjustDown_little(HpDataType* a, size_t n, size_t parent);//向下调整为小堆
void AdjustDown_big(HpDataType* a, size_t n, size_t parent);//向下调整为大堆
void Heapsort(Heap* hp);//升序(升序时候，要将堆向下调整为大堆）

void AdjustUp_little(HpDataType* a, size_t child);//向上调整为小堆
void AdjustUp_big(HpDataType* a, size_t child);//向上调整为大堆

void HeapPrint(Heap* hp);//打印
