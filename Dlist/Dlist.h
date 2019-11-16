#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int Datatype;
typedef struct ListNode
{
	Datatype _val;
	struct ListNode* _prev;
	struct ListNode* _next;
}ListNode;
typedef struct List
{
	ListNode* _head;
}List;

void ListInt(List* pcb);//初始化
void ListDestroy(List* pcb);//销毁
void List_print(List* pcb);//打印

void ListHead_insert(List* pcb, Datatype x);//头插
void ListHead_delete(List* pcb);//头删

void ListTail_insert(List* pcb, Datatype x);//尾插
void ListTail_delete(List* pcb);//尾删

ListNode* BuyListNode(int val);//创建新结点
ListNode* List_find(List* pcb, Datatype x);//查找

void ListFind_insert(ListNode* pos,Datatype x);//随机找值插入
void ListFind_delete(ListNode* pos1);//随机找值删除
