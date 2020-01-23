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

void AdjustDown_little(HpDataType* a, size_t n, size_t parent);//���µ���ΪС��
void AdjustDown_big(HpDataType* a, size_t n, size_t parent);//���µ���Ϊ���
void Heapsort(Heap* hp);//����(����ʱ��Ҫ�������µ���Ϊ��ѣ�

void AdjustUp_little(HpDataType* a, size_t child);//���ϵ���ΪС��
void AdjustUp_big(HpDataType* a, size_t child);//���ϵ���Ϊ���

void HeapPrint(Heap* hp);//��ӡ
