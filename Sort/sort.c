#include"sort.h"
#include"Stack.h"
void Insert_Sort(int* arr, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		if (arr[i + 1] < arr[i])//�ҵ���ǰһ������Ƚ�С�ĵ�ǰ��
		{
			int tmp = arr[i + 1];//�Ȱѵ�ǰ����������
			int j = i;//��J����¼��ǰ��ǰһ�������±�
			for (j; tmp < arr[j] && j >= 0; j--)
			{
				if (tmp < arr[j])
				{
					arr[j + 1] = arr[j];
				}
			}
			arr[j + 1] = tmp;
		}
	}
}

void Shellsert_Sort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//һ����gas/3,���һ��Ҫ�ǵ� +1������
		//ע��:��ѡȡ������ʱ����뱣֤���һ����������Ϊ1���������ܱ�֤ϣ���������ȷ��
		for (int i = 0; i < n - gap; i++)
			//˼����Ϊʲô i < n - gas����Ϊ����������һ�������һ��Ԫ���±���n - gas��
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + gap] = arr[end];
					end = end - gap;
				}
				else
				{
					break;
				}
			}
			//ע�����end�ı仯������������ûע��end�ı仯��������˺ܾã�����
			arr[end + gap] = tmp;
		}
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	    *p1 = *p2;
		*p2 = tmp;
}

void Slect_Sort(int* arr, int n)
{
	int begin = 0;
	int end = n - 1;
	int min_num;
	int max_num;
	while (begin <= end)
	{
		min_num = max_num = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (arr[i] < arr[min_num])
			{
				min_num = i;
			}
			if (arr[i]>arr[max_num])
			{
				max_num = i;
			}
		}
		Swap(&arr[begin], &arr[min_num]);

		//��ס����������ܶ�����Ȼ�Ļ����������
		//�������Ļ�û����������Ͳ��ԡ�
		if (max_num == begin)
		{
			max_num = min_num;
		}
		Swap(&arr[end], &arr[max_num]);
		begin++;
		end--;
	}
}

void AdjustDown_big(int* arr, int n,int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//���µ����㷨��һ��ǰ�᣺��������������һ���ѣ����ܵ�����
		if (child + 1 < n && arr[child] < arr[child + 1])
			++child;
		//ѡ���ϴ���Ǹ�����
		else if (arr[child]>arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}//������Ӵ��ڸ��ף��򽻻�
		else
		{
			break;
		}
	}
}

void Heap_Sort(int* arr, int n)
{
	//����֮ǰ�Ƚ��ѣ�����Ҫ�����
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown_big(arr, n, i);
	}
	int end = n - 1;
	while (end)
	{
		Swap(&arr[0], &arr[end]);
		--end;
		AdjustDown_big(arr, end, 0);
		//������β���ٽ������µ����㷨�����ɴ��
	}	
}

void Bubble_Sort(int* arr, int n)
{
	int end = n - 1;
	int count = 0;
	while (end)/* ��ѭ��Ϊ����������n��������n-1�� */
	{
		for (int i = 0; i < end; i++)/* ��ѭ��Ϊÿ�˱ȽϵĴ�������i�˱Ƚ�n-i�� */
		{
			if (arr[i]>arr[i + 1])
			{
				Swap(&arr[i], &arr[i + 1]);
				count++;
			}
		}
		if (count == 0)
			return;
		end--;
	}
}
int Getmid_index(int* arr, int left, int right)//����ȡ�з�(����������Ż�)
{
	int mid = left + (right - left) / 2;
	if (arr[left] < arr[right])
	{
		if (arr[right] < arr[mid])
		{
			return right;
		}
		else if (arr[left] < arr[mid])
		{
			return mid;
		}
		else
			return left;
	}
	//arr[left] > arr[right]
	else
	{
		if (arr[left]<arr[mid])
		{
			return left;
		}
		else if (arr[right] < arr[mid])
		{
			return mid;
		}
		return right;
	}
}

int part_lrpoint_quick(int* arr,int left,int right)//����ָ�뷨
{
	int key_index = Getmid_index(arr, left, right);
	Swap(&arr[key_index], &arr[right]);
	int key = arr[right];//key��������ұߣ������ָ���ȶ�       
	int right_index = right;
	while (left < right)
	{
		while (left < right&&arr[left] <= key)//left<right����������ܶ���
	   //�˲���left < rightһ��Ҫд����Ϊ������䱾���Ѿ�����begin��һֱ�����ߣ�ֱ���ߵ�end���������������
		{
			left++;
		}
		//��ʱleft��ָ���Ԫ�رȻ�׼ֵ��
		while (left < right&&arr[right] >= key)
		{
			right--;
		}
		//��ʱend��ָ���Ԫ�رȻ�׼ֵС
		Swap(&arr[left], &arr[right]);
	}
	              
	Swap(&arr[left], &arr[right_index]);
	return left;
}

int part_wakeng_quick(int* arr, int left, int right)//�ڿӷ�
{
	int key_index = Getmid_index(arr, left, right);
	Swap(&arr[key_index], &arr[right]);
	int key = arr[right];
	int right_index = right;
	while (left < right)
	{
		while (left < right&&arr[left] <= key)//����Ҵ�ģ����ұߵĿ�
		{
			left++;
		}
         arr[right] = arr[left];//���
		while (left < right&&arr[right] >= key)//�ұ���С�ģ�������ߵĿ�
		{
			right--;
		}
		arr[left] = arr[right];//���
	}
	arr[left] = key;
	return left;
}

int part_flpoint_quick(int* arr, int left, int right)//ǰ��ָ�뷨 former / latter
{
	int key_index = Getmid_index(arr, left, right);
	Swap(&arr[key_index], &arr[right]);
	int cur = left;
	int prev = left - 1;
	int key = arr[right];
	while (cur < right) //cur�ұ�keyС��Ԫ���ٽ��н���
	{
		if (arr[cur] < key && ++prev != cur)//prev������cur
		{
			Swap(&arr[cur], &arr[prev]);
		}
		cur++;
	}
	++prev;//����������ܶ�
	Swap(&arr[right], &arr[prev]);
	return prev;
}

//����-�ݹ鷽��
void quick_Sort1(int* arr, int left, int right)
{
	if (left >= right)
		return;
	if (right - left + 1 > 10)//����������Ż�
	{
    	int key_index = part_lrpoint_quick(arr, left, right);//����ָ�뷨
		quick_Sort1(arr, left, key_index - 1);
		quick_Sort1(arr, key_index + 1, right);

		//int key_index = part_wakeng_quick(arr, left, right);//�ڿӷ�
		//quick_Sort1(arr, left, key_index - 1);
		//quick_Sort1(arr, key_index + 1, right);

		//int key_index = part_flpoint_quick(arr, left, right);//ǰ��ָ�뷨
		//quick_Sort1(arr, left, key_index - 1);
		//quick_Sort1(arr, key_index + 1, right);

	  }
   else 
	{
	   Insert_Sort(arr + left, right - left + 1);
	}
}

//����-�ǵݹ鷽��
void quick_Sort2(int* arr, int left, int right)
{
	Stack s;
	StackInit(&s);
	StackPush(&s, left);
	StackPush(&s, right);
	while (StackEmpty(&s))
	{
		int end = Stacktop(&s);
		StackPop(&s);
		int begin = Stacktop(&s);
		StackPop(&s);

		int key_index = part_flpoint_quick(arr, begin, end);
		//[begin,key_index - 1] key_index [ key_index + 1,end]
		if (begin < key_index - 1)
		{
			StackPush(&s, begin);
			StackPush(&s, key_index - 1);
		}
		if (key_index + 1 < end)
		{
			StackPush(&s, key_index + 1);
			StackPush(&s, end);
		}
	}
}

//�鲢����-�ݹ鷽��
void MergeArrary(int* arr, int left, int mid, int right, int* tmp)
{
	int begin1  = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int tmp_index = left;
	//���������������û�б����꣬��һֱ������ĳ�������������
	while (begin1 <= mid && begin2 <= end2)
	{
		//��ֵ��С��Ԫ�ظ��Ƶ��µ�����
		if (arr[begin1] < arr[begin2])
		{
			tmp[tmp_index] = arr[begin1];
			tmp_index++;
			begin1++;
		}
		else
		{
			tmp[tmp_index] = arr[begin2];
			tmp_index++;
			begin2++;
		}
	}
	//��δ��������������ʣ��Ԫ�ظ�ֵ��������
	while (begin1 <= mid)
	{
		tmp[tmp_index] = arr[begin1];
		tmp_index++;
		begin1++;
	}
	while (begin2 <= right)
	{
		tmp[tmp_index] = arr[begin2];
		tmp_index++;
		begin2++;
	}
	memcpy(arr + left, tmp + left, sizeof(int)*(right - left+1));
	return;
}
void _Merge_Sort(int* arr, int left, int right, int* tmp)
{
	if (left == right)
		return;
	int mid = left + (right - left) / 2;

	//�������Ϊ [left,mid] [mid+1,right]
	_Merge_Sort(arr, left, mid, tmp);
	_Merge_Sort(arr, mid+1, right, tmp);

	// a[left, mid] a[mid+1, right]�鲢��tmp[left, right]
	MergeArrary(arr, left, mid, right, tmp);
}
void Merge_Sort1(int* arr, int left, int right)
{
	int n = right - left + 1;
	int* tmp = (int*)malloc(sizeof(int)*n);//����һ��������
	if (tmp == NULL)
	{
		printf("malloc error");
		exit(-1);
	}

	//���¶���һ��������������õݹ�ʱ���������ٿռ�
	_Merge_Sort(arr, left, right, tmp);
	free(tmp);
}


//�鲢����-�ǵݹ鷽��
void Merge_Sort2(int* arr, int left, int right)
{
	int n = right - left + 1;
	int gap = 1;
	int* tmp = (int*)malloc(sizeof(int)*n);
	while (gap < n)
	{
		for (int begin = 0; begin < n; begin += 2*gap)
		{
			//[begin, begin + gap - 1] [begin+gap,begin+2*gap-1]
			int begin1 = begin;
			int end1 = begin + gap - 1;
			if (end1 >= n)
			{
				end1 = n - 1;
			}
			int begin2 = begin + gap;
			int end2 = begin + 2 * gap - 1;
			if (end2 >= n)//������������жϣ���������� >= n ,���� end2 �ص� n-1;
				          //��ֹ���ֻʣ��һ�����䣬�Ӷ��޷����кϲ�

			{
				end2 = n - 1;
			}
			int tmp_index = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (arr[begin1] < arr[begin2])
				{
					tmp[tmp_index] = arr[begin1];
					tmp_index++;
					begin1++;
				}
				else
				{
					tmp[tmp_index] = arr[begin2];
					tmp_index++;
					begin2++;
				}
			}
			while (begin1 <= end1)
			{
				tmp[tmp_index] = arr[begin1];
				tmp_index++;
				begin1++;
			}
			while (begin2 <= end2)
			{
				tmp[tmp_index] = arr[begin2];
				tmp_index++;
				begin2++;
			}
		}
		memcpy(arr, tmp, sizeof(int)*n);
		gap *= 2;//gapÿһ������2��
	}
	free(tmp);
}

//��������
void CountSort(int* arr, int left, int right)
{
	int n = right - left + 1;
	int minvalue = arr[0];
	int maxvalue = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < minvalue)
		{
			minvalue = arr[i];
		}
		if (arr[i]>maxvalue)
		{
			maxvalue = arr[i];
		}
	}
	int range = maxvalue - minvalue + 1;

	int* tmp = (int*)malloc(sizeof(int)*range);
	if (tmp == NULL)
	{
		printf("malloc error");
	}
	memset(tmp, 0, sizeof(int)*range);
	//��ʼ���������飬memset����ֻ�ܽ����������ʼ��Ϊ 0 �� �����ܳ�ʼ��Ϊ����ֵ
	//���Ҫ��ʼ��Ϊ����ֵ��Ӧ�ÿ���forѭ��

	//ͳ�ƴ���
	for (int i = 0; i < n; i++)
	{
		tmp[arr[i] - minvalue]++;
	}

	//ͨ��ͳ��tmp[];����Ԫ��
	int count = 0;
	for (int i = 0; i < range; i++)
	{
		while (tmp[i]--)
		{
			arr[count] = i + minvalue;
			count++;
		}
	}
	free(tmp);
}