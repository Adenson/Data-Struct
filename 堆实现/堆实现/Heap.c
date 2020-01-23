#include"Heap.h"
void HeapInit(Heap* hp, HpDataType* a, size_t n)
{
	hp->_a = (HpDataType*)malloc(sizeof(HpDataType)*n);
	memcpy(hp->_a, a, sizeof(HpDataType)*n);
	hp->_size = n;
	hp->_capacity = n;

	//�����ɶ�
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
	//���µ����㷨��һ��ǰ�᣺��������������һ���ѣ����ܵ�����
	size_t child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1 < n && a[child]>a[child + 1])
			++child;
		//ѡ����С���Ǹ�����

	    if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}//�������С�ڸ��ף��򽻻�
		else
		{
			break;
		}
	}	
}
void AdjustUp_little(HpDataType* a, size_t child)//˳���߼��ṹ(�������е���һ���߽������ϵ���
{
	size_t parent = (child - 1) / 2;
	while (child > 0)//�˴�child>0,��Ӧ��>=0
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
	if (hp->_size == hp->_capacity)//�жϿռ��Ƿ񹻴�,�������������
	{
		int newcapacity = hp->_capacity == 0 ? 2 : hp->_capacity * 2;
		hp->_a = (HpDataType*)realloc(hp->_a, sizeof(HpDataType)*newcapacity);
		if (hp->_a == NULL)
		{
			printf("realloc error");
		}
		hp->_capacity = newcapacity;
	}
	//�Ȳ�����������ϵ���
	hp->_a[hp->_size] = x;
	++hp->_size;
	AdjustUp_little(hp->_a, hp->_size - 1);
}

void HeapPop(Heap* hp)//�Ȱ����һ���ڵ�͸��ڵ㽻����ɾ�����һ����㣬֮�������µ����㷨
{
	assert(hp && hp->_size > 0);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);//�ǵô���ַ
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
		//���µ����㷨��һ��ǰ�᣺��������������һ���ѣ����ܵ�����
		size_t child = parent * 2 + 1;
		while (child < n)
		{
			if (child + 1 < n && a[child] < a[child + 1])
				++child;
			//ѡ���ϴ���Ǹ�����

			else if (a[child] > a[parent])
			{
				Swap(&a[child], &a[parent]);
				parent = child;
				child = parent * 2 + 1;
			}//������Ӵ��ڸ��ף��򽻻�
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
		AdjustDown_big(hp->_a, hp->_size, i);//����ʱ�����µ���Ϊ���
	}
	for (size_t i = 0; i < n; ++i)
	{
		Swap(&hp->_a[0], &hp->_a[n - 1 - i]);
		AdjustDown_big(hp->_a, n - 1 - i,0 );
	}

	//����
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

