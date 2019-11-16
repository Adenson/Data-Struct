#include"Heap.h"
void HeapInit(Heap* hp, HpDataType* a, size_t n)
{
	hp->_a = (HpDataType*)malloc(sizeof(HpDataType)*n);
	memcpy(hp->_a, a, sizeof(HpDataType)*n);
	hp->_size = n;
	hp->_capacity = n;

	//构建成堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown_little(hp->_a, hp->_size, i);
	}
}
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_size = 0;
	hp->_capacity = 0;
}
void Swap(HpDataType* p1, HpDataType* p2)
{
	HpDataType  tem = *p1;
	            *p1 = *p2;
				*p2 = tem;
}
void AdjustDown_little(HpDataType* a, size_t n, size_t parent)
{
	//向下调整算法有一个前提：左右子树必须是一个堆，才能调整。
	size_t child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1 < n && a[child]>a[child + 1])
			++child;
		//选出较小的那个孩子

	    if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}//如果孩子小于父亲，则交换
		else
		{
			break;
		}
	}	
}
void AdjustUp_little(HpDataType* a, size_t child)//顺着逻辑结构(树）当中的那一条线进行向上调整
{
	size_t parent = (child - 1) / 2;
	while (child > 0)//此处child>0,不应该>=0
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(Heap* hp, HpDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)//判断空间是否够存,如果不够则扩容
	{
		int newcapacity = hp->_capacity == 0 ? 2 : hp->_capacity * 2;
		hp->_a = (HpDataType*)realloc(hp->_a, sizeof(HpDataType)*newcapacity);
		if (hp->_a == NULL)
		{
			printf("realloc error");
		}
		hp->_capacity = newcapacity;
	}
	//先插入最后，再向上调整
	hp->_a[hp->_size] = x;
	++hp->_size;
	AdjustUp_little(hp->_a, hp->_size - 1);
}

void HeapPop(Heap* hp)//先把最后一个节点和根节点交换，删除最后一个结点，之后用向下调整算法
{
	assert(hp && hp->_size > 0);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);//记得传地址
	--hp->_size;
	AdjustDown_little(hp->_a, hp->_size, 0);
}

void HeapPrint(Heap* hp)
{
	assert(hp);
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
}

void AdjustDown_big(HpDataType* a, size_t n, size_t parent)
{
	{
		//向下调整算法有一个前提：左右子树必须是一个堆，才能调整。
		size_t child = parent * 2 + 1;
		while (child < n)
		{
			if (child + 1 < n && a[child] < a[child + 1])
				++child;
			//选出较大的那个孩子

			else if (a[child] > a[parent])
			{
				Swap(&a[child], &a[parent]);
				parent = child;
				child = parent * 2 + 1;
			}//如果孩子大于父亲，则交换
			else
			{
				break;
			}
		}
	}
}
void Heapsort(Heap* hp)
{
	assert(hp);
	size_t n = hp->_size;
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown_big(hp->_a, hp->_size, i);//升序时，向下调整为大堆
	}
	for (size_t i = 0; i < n; ++i)
	{
		Swap(&hp->_a[0], &hp->_a[n - 1 - i]);
		AdjustDown_big(hp->_a, n - 1 - i,0 );
	}

	//或者
	//int end = hp->_size - 1;
	//while (end)
	//{
	//	Swap(&hp->_a[0], &hp->_a[end]);
	//	end--;
	//	AdjustDown_big(hp->_a, end, 0);
	//}
}

HpDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_a == NULL ? 0 : 1;
}

