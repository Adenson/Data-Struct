void BubbleSort(int* arr, int n)
{
	while (--n)
	{
		int counts = 0;
		for (int i = 0; i < n; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				counts++;
				swap(arr[i], arr[i + 1]);
			}
		}
		if (counts == 0){
			return;
		}
	}
}

void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			int tmp = arr[i + 1];
			int j = i;
			for (j; j >= 0 && tmp < arr[j]; j--)//此处不一定能忘记了tmp < arr[j] 这个条件；防止这样子的数据arr[1,3,2,4]
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

void ShellsertSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / n + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int start = i;
			int tmp = arr[i + gap];
			while (start >= 0)
			{
				if (arr[start] > tmp)
				{
					arr[ start + gap] = arr[start];
					start -= gap;
				}
				else
				{
					break;
				}
			}
			arr[start += gap] = tmp;
		}
	}
}

void adjustDown(int* arr, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n&&arr[child] < arr[child + 1])
		{
			child++;
		}

		if (arr[child] > arr[parent])
		{
			swap(arr[child], arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}
void HeapSort(int* arr, int n)
{
	//升序建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		adjustDown(arr, n, i);
	}

	int end = n - 1;
	while (end)
	{
		swap(arr[0], arr[end]);
		adjustDown(arr, end, 0);//logN
		end--;
	}
}

void SelectSort(int* arr, int n)//为了更好优化直接选择排序，我在这里实现了同时找最大和最小的数据元素
{
	int begin = 0;
	int end = n - 1;
	int min_index = 0;
	int max_index = 0;
	while (begin <= end)
	{
		min_index = begin;
		max_index = begin;
		int tmp = begin + 1;
		for (tmp; tmp <= end; tmp++)
		{
			if (arr[tmp] < arr[min_index])
			{
				min_index = tmp;
			}
			if (arr[tmp]>arr[max_index])
			{
				max_index = tmp;
			}
		}
		swap(arr[begin], arr[min_index]);

		if (max_index == begin)
		{
			max_index = min_index;
		}
		swap(arr[end], arr[max_index]);
		begin++;
		end--;
	}
}

int GetMidIndex(int* arr, int left, int right)
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
		{
			return left;
		}
	}

	if (arr[right] < arr[left])
	{
		if (arr[left] < arr[mid])
		{
			return left;
		}
		else if (arr[right] < arr[mid])
		{
			return mid;
		}
		else
		{
			return right;
		} 
	}
	return right;
}
int QuickSortLR(int* arr, int left, int right)
{
	int midValueIndex = GetMidIndex(arr, left, right);
	swap(arr[midValueIndex], arr[right]);
	int keyValue = arr[right];
	int keyvalue_index = right;
	while (left < right)
	{
		while (left < right && arr[left] <= keyValue)
		{
			left++;
		}
		while (left < right && arr[right] >= keyValue)
		{
			right--;
		}
		swap(arr[right], arr[left]);
	}
	swap(arr[keyvalue_index], arr[right]);
	return right;
}

int QuickSortHole(int* arr, int left, int right)
{
	int midValueIndex = GetMidIndex(arr, left, right);
	swap(arr[midValueIndex], arr[right]);
	int keyValue = arr[right];

	while(left < right)
	{
		while (left < right && arr[left] <= keyValue)
		{
			left++;
		}
		arr[right] = arr[left];

		while (left < right && arr[right] >= keyValue)
		{
			right--;
		}
		arr[left] = arr[right];
	}
	arr[left] = keyValue;
	return left;
}

int QuickSortFB(int* arr, int left, int right)
{
	int keyIndex = GetMidIndex(arr, left, right);
	swap(arr[keyIndex], arr[right]);
	int keyValue = arr[right];
	int prev = left - 1;//这里不能用0，应为还有递归
	int cur = left;//cur找小
	while (cur < right)
	{
		if (arr[cur] < keyValue)//如果cur找到比keyValue大的值就停下来
		{
			if (prev++ != cur)
			{
				prev++;
				swap(arr[prev], arr[cur]);
			}
		}
		cur++;
	}
	prev++;
	return prev;
}
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	if (right - left + 1 > 10)
	{
		int value = QuickSortHole(arr, left, right);
		QuickSort(arr, left, value - 1);
		QuickSort(arr, value + 1, right);
	}
	else{
		InsertSort(arr + left, right - left + 1);
	}
}
int main()
{
	int arr[] = { 103, 102, 100, 9, 1, 2, 10000, 5, 7, 4, 8, 0, 6, 3, 5, 111 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//BubbleSort(arr, n);
	//InsertSort(arr, n);
	//ShellsertSort(arr, n);
	//HeapSort(arr, n);
	//SelectSort(arr, n);
	int left = 0;
	int right = n - 1;
	//QuickSort(arr, left, right);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}
