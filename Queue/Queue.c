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

	if (pq->_front == NULL)//要判断pq->_front是不是为空，当pq->_front为空时，已经将pq->_rear
	{                      //free掉，现在pq->_rear是一个野指针，所以必须得将pq->_rear置空
		pq->_rear = NULL;
	}

	//或者这种释放
	/*assert(pq);
	QueueNode* cur = pq->_front;
	if (cur != NULL)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
		pq->_front = cur;//这句代码加上才能对
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