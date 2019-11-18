#pragma once
//��ͷ�����ѭ������
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SlistDataType;
typedef struct SlistNode//ÿ���ڵ���һ���ṹ��
{
	SlistDataType _data;//������
	struct SlistNode* _next;//ָ����
}SlistNode;

typedef struct Slist
{
	SlistNode* _head;
}Slist;

void  Slist_Int(Slist* pcb);

void  SList_Tail_Insert(Slist* pcb, SlistDataType x);//β��
void  Slist_Tail_Delete(Slist* pcb);//βɾ

void  Slist_Head_Insert(Slist* pcb, SlistDataType x);//ͷ��
void  Slist_Head_Delete(Slist* pcb);//ͷɾ

SlistNode* Slist_Find(Slist* pcb, SlistDataType x);//����

void Slist_Insert_After(SlistNode* pos, SlistDataType x);//��POS�ĺ�����в���
void Slist_Erase_After(SlistNode* pos);//��pos�������һ��ɾ��

void Slist_Insert_Front(SlistNode* pos, SlistDataType x);//��pos��ǰ����в���
void Slist_Erase_Front(SlistNode * pos, SlistDataType x);//��POS��ǰ����һ��ɾ��

void Slist_Remove(Slist* pcb, SlistDataType x);//�ҳ�һ���������ظ����ݵĵ�һ������ɾ��
void Slist_All_Remove(Slist* pcb, SlistDataType x);//ɾ���� X ��ͬ����������
void Slist_Print(Slist* pcb);//��ӡ