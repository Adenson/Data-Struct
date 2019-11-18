#pragma once
//无头单向非循环链表
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SlistDataType;
typedef struct SlistNode//每个节点是一个结构体
{
	SlistDataType _data;//数据域
	struct SlistNode* _next;//指针域
}SlistNode;

typedef struct Slist
{
	SlistNode* _head;
}Slist;

void  Slist_Int(Slist* pcb);

void  SList_Tail_Insert(Slist* pcb, SlistDataType x);//尾插
void  Slist_Tail_Delete(Slist* pcb);//尾删

void  Slist_Head_Insert(Slist* pcb, SlistDataType x);//头插
void  Slist_Head_Delete(Slist* pcb);//头删

SlistNode* Slist_Find(Slist* pcb, SlistDataType x);//查找

void Slist_Insert_After(SlistNode* pos, SlistDataType x);//在POS的后面进行插入
void Slist_Erase_After(SlistNode* pos);//把pos后面的那一个删除

void Slist_Insert_Front(SlistNode* pos, SlistDataType x);//在pos的前面进行插入
void Slist_Erase_Front(SlistNode * pos, SlistDataType x);//把POS的前面那一个删除

void Slist_Remove(Slist* pcb, SlistDataType x);//找出一组数据中重复数据的第一个进行删除
void Slist_All_Remove(Slist* pcb, SlistDataType x);//删除与 X 相同的所有数据
void Slist_Print(Slist* pcb);//打印