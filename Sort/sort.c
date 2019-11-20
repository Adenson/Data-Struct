#include"sort.h"
#include"Stack.h"
void Insert_Sort(int* arr, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		if (arr[i + 1] < arr[i])//找到比前一个数相比较小的当前数
		{
			int tmp = arr[i + 1];//先把当前数保存下来
			int j = i;//用J来记录当前数前一个数的下标
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
		gap = gap / 3 + 1;//一般是gas/3,最后一定要记得 +1！！！
		//注意:在选取步长的时候必须保证最后一个增量必须为1，这样才能保证希尔排序的正确性
		for (int i = 0; i < n - gap; i++)
			//思考：为什么 i < n - gas，因为步数最多的那一个的最后一个元素下标是n - gas；
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
			//注意最后end的变化，当初在这里没注意end的变化导致理解了很久！！！
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

		//记住这个条件不能丢，不然的话会出错！！！
		//如果逆序的话没有这个条件就不对。
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
		//向下调整算法有一个前提：左右子树必须是一个堆，才能调整。
		if (child + 1 < n && arr[child] < arr[child + 1])
			++child;
		//选出较大的那个孩子
		else if (arr[child]>arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}//如果孩子大于父亲，则交换
		else
		{
			break;
		}
	}
}

void Heap_Sort(int* arr, int n)
{
	//排序之前先建堆，升序要建大堆
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
		//交换首尾，再进行向下调整算法构建成大堆
	}	
}

void Bubble_Sort(int* arr, int n)
{
	int end = n - 1;
	int count = 0;
	while (end)/* 外循环为排序趟数，n个数进行n-1趟 */
	{
		for (int i = 0; i < end; i++)/* 内循环为每趟比较的次数，第i趟比较n-i次 */
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
int Getmid_index(int* arr, int left, int right)//三数取中法(快速排序的优化)
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

int part_lrpoint_quick(int* arr,int left,int right)//左右指针法
{
	int key_index = Getmid_index(arr, left, right);
	Swap(&arr[key_index], &arr[right]);
	int key = arr[right];//key如果定在右边，则左边指针先动       
	int right_index = right;
	while (left < right)
	{
		while (left < right&&arr[left] <= key)//left<right这个条件不能丢掉
	   //此步的left < right一定要写，因为如果区间本身已经有序，begin会一直往右走，直到走到end，还会继续往右走
		{
			left++;
		}
		//此时left所指向的元素比基准值大
		while (left < right&&arr[right] >= key)
		{
			right--;
		}
		//此时end所指向的元素比基准值小
		Swap(&arr[left], &arr[right]);
	}
	              
	Swap(&arr[left], &arr[right_index]);
	return left;
}

int part_wakeng_quick(int* arr, int left, int right)//挖坑法
{
	int key_index = Getmid_index(arr, left, right);
	Swap(&arr[key_index], &arr[right]);
	int key = arr[right];
	int right_index = right;
	while (left < right)
	{
		while (left < right&&arr[left] <= key)//左边找大的，放右边的坑
		{
			left++;
		}
         arr[right] = arr[left];//填坑
		while (left < right&&arr[right] >= key)//右边找小的，放在左边的坑
		{
			right--;
		}
		arr[left] = arr[right];//填坑
	}
	arr[left] = key;
	return left;
}

int part_flpoint_quick(int* arr, int left, int right)//前后指针法 former / latter
{
	int key_index = Getmid_index(arr, left, right);
	Swap(&arr[key_index], &arr[right]);
	int cur = left;
	int prev = left - 1;
	int key = arr[right];
	while (cur < right) //cur找比key小的元素再进行交换
	{
		if (arr[cur] < key && ++prev != cur)//prev紧贴着cur
		{
			Swap(&arr[cur], &arr[prev]);
		}
		cur++;
	}
	++prev;//这个条件不能丢
	Swap(&arr[right], &arr[prev]);
	return prev;
}

//快排-递归方法
void quick_Sort1(int* arr, int left, int right)
{
	if (left >= right)
		return;
	if (right - left + 1 > 10)//快速排序的优化
	{
    	int key_index = part_lrpoint_quick(arr, left, right);//左右指针法
		quick_Sort1(arr, left, key_index - 1);
		quick_Sort1(arr, key_index + 1, right);

		//int key_index = part_wakeng_quick(arr, left, right);//挖坑法
		//quick_Sort1(arr, left, key_index - 1);
		//quick_Sort1(arr, key_index + 1, right);

		//int key_index = part_flpoint_quick(arr, left, right);//前后指针法
		//quick_Sort1(arr, left, key_index - 1);
		//quick_Sort1(arr, key_index + 1, right);

	  }
   else 
	{
	   Insert_Sort(arr + left, right - left + 1);
	}
}

//快排-非递归方法
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

//归并排序-递归方法
void MergeArrary(int* arr, int left, int mid, int right, int* tmp)
{
	int begin1  = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int tmp_index = left;
	//如果两个有序数组没有遍历完，就一直遍历到某个数组遍历结束
	while (begin1 <= mid && begin2 <= end2)
	{
		//将值较小的元素复制到新的数组
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
	//将未遍历完的子数组的剩余元素赋值到新数组
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

	//将数组分为 [left,mid] [mid+1,right]
	_Merge_Sort(arr, left, mid, tmp);
	_Merge_Sort(arr, mid+1, right, tmp);

	// a[left, mid] a[mid+1, right]归并到tmp[left, right]
	MergeArrary(arr, left, mid, right, tmp);
}
void Merge_Sort1(int* arr, int left, int right)
{
	int n = right - left + 1;
	int* tmp = (int*)malloc(sizeof(int)*n);//定义一个新数组
	if (tmp == NULL)
	{
		printf("malloc error");
		exit(-1);
	}

	//重新定义一个函数，避免调用递归时候连续开辟空间
	_Merge_Sort(arr, left, right, tmp);
	free(tmp);
}


//归并排序-非递归方法
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
			if (end2 >= n)//加上这个条件判断，如果右区间 >= n ,则让 end2 回到 n-1;
				          //防止最后只剩余一个区间，从而无法进行合并

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
		gap *= 2;//gap每一次扩大2倍
	}
	free(tmp);
}

//计数排序
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
	//初始化辅助数组，memset函数只能将整形数组初始化为 0 ， 而不能初始化为其他值
	//如果要初始化为其他值，应该考虑for循环

	//统计次数
	for (int i = 0; i < n; i++)
	{
		tmp[arr[i] - minvalue]++;
	}

	//通过统计tmp[];回收元素
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