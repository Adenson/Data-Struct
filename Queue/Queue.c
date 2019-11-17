#include"Queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = NULL;
	pq->_rear = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = pq->_rear = NULL;
}
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	QueueNode* newnode = BuyQueueNode(x);
	if (pq->_rear == NULL)
	{
		pq->_front = pq->_rear = newnode;
	}
	else
	{
		pq->_rear->_next = newnode;
		pq->_rear = newnode;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq && pq->_front != NULL);

	QueueNode* next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;

	if (pq->_front == NULL)//Ҫ�ж�pq->_front�ǲ���Ϊ�գ���pq->_frontΪ��ʱ���Ѿ���pq->_rear
	{                      //free��������pq->_rear��һ��Ұָ�룬���Ա���ý�pq->_rear�ÿ�
		pq->_rear = NULL;
	}

	//���������ͷ�
	/*assert(pq);
	QueueNode* cur = pq->_front;
	if (cur != NULL)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
		pq->_front = cur;//��������ϲ��ܶ�
	}
	else
	{
		pq->_rear = NULL;
	}*/
}
QUDataType QueueFront(Queue* pq)
{
	assert(pq && pq->_front != NULL);
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq)
{
	assert(pq && pq->_rear != NULL);
	return pq->_rear->_data;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return  pq->_front == NULL ? 0 : 1;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	if (pq->_front == NULL)
	{
		return 0;
	}
	QueueNode* cur = pq->_front;
	while (cur != NULL)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}