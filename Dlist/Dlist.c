#include"Dlist.h"
ListNode* BuyListNode(Datatype val)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_next = NULL;
	newnode->_prev = NULL;
	newnode->_val = val;
	return newnode;
}
void ListInt(List* pcb)
{
	assert(pcb);
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->_next = head;
	head->_prev = head;
	pcb->_head = head;
}

void ListTail_insert(List* pcb, Datatype x)
{
	assert(pcb);
	ListNode* head = pcb->_head;
	//ListNode* tail = head->_prev; 
	//ListNode* newnode = BuyListNode(x);
	//newnode->_prev = tail;
	//tail->_next = newnode;
	//head->_prev = newnode;
	//newnode->_next = head;

	//或者
	ListFind_insert(head, x);
}
void ListTail_delete(List* pcb)
{
	assert(pcb);
	ListNode* head = pcb->_head;
	//ListNode* tail = head->_prev;
	//ListNode* pre_tail = tail->_prev;
	//head->_prev = pre_tail;
	//pre_tail->_next = head;
	//free(tail);

	//或者
	ListFind_delete(head->_prev);
}
void ListHead_insert(List* pcb, Datatype x)
{
	assert(pcb);
	ListNode* head = pcb->_head;
	//ListNode* phead = head->_next;
	//ListNode* newnode = BuyListNode(x);
	//head->_next = newnode;
	//newnode->_prev = head;
	//newnode->_next = phead;
	//phead->_prev = newnode;

	//或者
	ListFind_insert(head->_next, x);
}
void ListHead_delete(List* pcb)
{
	assert(pcb);
	ListNode* head = pcb->_head;
	//ListNode* first_head = head->_next;
	//ListNode* second_head = first_head->_next;
	//head->_next= second_head;
	//second_head->_prev = head;
	//free(first_head);

	//或者
	ListFind_delete(head->_next);
}
ListNode* List_find(List* pcb, Datatype x)
{
	assert(pcb);
	ListNode* head = pcb->_head;
	ListNode* cur = head->_next;
	while (cur != head)
	{
		if (cur->_val == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

void ListFind_insert(ListNode* pos,Datatype x)
{
	assert(pos);
	ListNode* prev_pos = pos->_prev;
	ListNode* newnode = BuyListNode(x);
	prev_pos->_next = newnode;
	newnode->_prev = prev_pos;
	newnode->_next = pos;
	pos->_prev = newnode;
}

void ListFind_delete(ListNode* pos1)
{
	assert(pos1);
	ListNode* pos1_next = pos1->_next;
	ListNode* pre_pos1 = pos1->_prev;
	pre_pos1->_next = pos1_next;
	pos1_next->_prev = pre_pos1;
	free(pos1);
}
void List_print(List* pcb)
{
	assert(pcb);
	ListNode* head = pcb->_head;
	ListNode* cur = head->_next;
	printf("head<=>");
	while (cur != head)
	{
		printf("%d<=>", cur->_val);
		cur = cur->_next;
	}
	printf("\n");
}
void ListDestroy(List* pcb)
{
	assert(pcb);
	ListNode* head = pcb->_head;
	ListNode* cur = head->_next;
	ListNode* next = NULL;
	while (cur != head)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
}