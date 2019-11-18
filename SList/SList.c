#include"SList.h"

void  Slist_Int(Slist* pcb)
{
	assert(pcb);
	pcb->_head = NULL;
}
void SList_Tail_Insert(Slist* pcb, SlistDataType x)
{
	assert(pcb);
	SlistNode* newnode = (SlistNode*)malloc(sizeof(SlistNode));
	if (newnode == NULL)
	{
		printf("malloc error");
		exit(-1);
	}
	newnode->_data = x;
	newnode->_next = NULL;

	if (pcb->_head == NULL)//为空时
	{
		pcb->_head = newnode;
	}
	else//非空时
	{
		SlistNode* cur = pcb->_head;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}
}
void  Slist_Tail_Delete(Slist* pcb)
{
	assert(pcb);
	SlistNode* cur = pcb->_head;
	if (cur == NULL)//没有节点时
	{
		return;
	}
	else if(cur->_next == NULL)
	{
		free(cur);
		pcb->_head = NULL;
	}
	else
	{
		while (cur->_next->_next != NULL)
		{
			cur = cur->_next;
		}
		free(cur->_next);
		cur->_next = NULL;
	}
}
void  Slist_Head_Insert(Slist* pcb, SlistDataType x)
{
	assert(pcb);
	SlistNode* newnode = (SlistNode*)malloc(sizeof(SlistNode));
	{
		if (newnode == NULL)
		{
			printf("newnode error");
			exit(-1);
		}
		newnode->_data = x;
		newnode->_next = NULL;

		newnode->_next = pcb->_head;
		pcb->_head = newnode;
	}
}	
void  Slist_Head_Delete(Slist* pcb)
{
	assert(pcb);
	SlistNode* cur = pcb->_head;
	if (cur == NULL)
	{
		return;
	}
	else 
	{
      pcb->_head = cur->_next;
	  free(cur);
	  cur = NULL;
	}
}
void Slist_Print(Slist* pcb)
{
	assert(pcb);
	SlistNode* cur = pcb->_head;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}
SlistNode* Slist_Find(Slist* pcb, SlistDataType x)
{
	assert(pcb);
	SlistNode* cur = pcb->_head;
	while (cur!= NULL)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
void  Slist_Insert_After(SlistNode* pos, SlistDataType x)
{
	assert(pos);
	SlistNode* newnode = (SlistNode*)malloc(sizeof(SlistNode));
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_next = pos->_next;
	pos->_next = newnode;
}
void Slist_Erase_After(SlistNode* pos)
{
	assert(pos);
	if (pos->_next == NULL)
	{
		return;
	}
	else
	{
		SlistNode* next = pos->_next;
		pos->_next = next->_next;
		free(next);
		next = NULL;
	}
}
void Slist_Insert_Front(Slist* pcb,SlistNode* pos, SlistDataType x)
{
	assert(pcb);
	assert(pos);
	SlistNode* newnode = (SlistNode*)malloc(sizeof(SlistNode));
	newnode->_data = x;
	newnode->_next = NULL;
	SlistNode* cur = pcb->_head;
	SlistNode* pcur = NULL;
	while (cur != NULL)
	{
		if (cur->_data == pos->_data)
		{
			if (pcur == NULL)
			{
				pcb->_head = newnode;
				newnode->_next = cur;
			}
			else
			{
			   pcur->_next = newnode;
			   newnode->_next = cur;
			}
			return;
		}
		else
		{
			pcur = cur;
			cur = cur->_next;
		}
	}
}
void Slist_Remove(Slist* pcb, SlistDataType x)
{
	assert(pcb);
	SlistNode* cur = pcb->_head;
	SlistNode* pcur = NULL; 
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			if (pcur == NULL)
				pcb->_head = cur->_next;
			else
				pcur->_next = cur->_next;
			free(cur);
			cur = NULL;
			return;
		}
		else
		{
			pcur = cur;
			cur = cur->_next;
		}
	}
}
void Slist_All_Remove(Slist* pcb, SlistDataType x)
{
	assert(pcb);
	SlistNode* cur = pcb->_head;
	SlistNode* prev = NULL;
	SlistNode* next = NULL;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			next = cur->_next;
			free(cur);
			cur = NULL;
			cur = next;
			if (prev == NULL)
			{
				pcb->_head = next;
			}
			else
			{
				prev->_next = cur;
			}
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
	return pcb->_head;
}