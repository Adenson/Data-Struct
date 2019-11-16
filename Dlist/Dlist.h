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

void ListInt(List* pcb);//��ʼ��
void ListDestroy(List* pcb);//����
void List_print(List* pcb);//��ӡ

void ListHead_insert(List* pcb, Datatype x);//ͷ��
void ListHead_delete(List* pcb);//ͷɾ

void ListTail_insert(List* pcb, Datatype x);//β��
void ListTail_delete(List* pcb);//βɾ

ListNode* BuyListNode(int val);//�����½��
ListNode* List_find(List* pcb, Datatype x);//����

void ListFind_insert(ListNode* pos,Datatype x);//�����ֵ����
void ListFind_delete(ListNode* pos1);//�����ֵɾ��
