#include"sort.h"
void InterSort_test()
{
	int arr[] = { 4, 3, 2, 8, 0, 9, 7, 8, 5, 4, 8, 9, 5, 6, 4 };
	int n = sizeof(arr) / sizeof(int);
	Insert_Sort(arr, n);
	printf("直接插入排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void ShellSort_test()
{
	int arr[] = { 4, 3, 2, 8, 0, 9, 7, 8, 5, 4, 8, 9, 5, 6, 4 };
	int n = sizeof(arr) / sizeof(int);
	Shellsert_Sort(arr, n);
	printf("希尔排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void SlectSort_test()
{
	int arr[] = { 4, 3, 2, 8, 0, 9, 7, 8, 5, 4, 8, 9, 5, 6, 4 };
	int n = sizeof(arr) / sizeof(int);
	Slect_Sort(arr, n);
	printf("选择排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void HeapSort_test()
{
	int arr[] = { 4, 3, 2, 8, 0, 9, 7, 8, 5, 4, 8, 9, 5, 6, 4 };
	int n = sizeof(arr) / sizeof(int);
	Heap_Sort(arr, n);
	printf("堆排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void BubbleSort_test()
{
	int arr[] = { 4, 3, 2, 8, 0, 9, 7, 8, 5, 4, 8, 9, 5, 6, 4 };
	int n = sizeof(arr) / sizeof(int);
	Bubble_Sort(arr, n);
	printf("冒泡排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void quickSort_test1()//递归算法
{
	int arr[] = { 4, 3, 2, 8, 0, 9, 7, 8, 5, 4, 8, 9, 5, 6, 4 };
	int n = sizeof(arr) / sizeof(int);
	int left = 0;
	int right = n - 1;
	quick_Sort1(arr, left, right);
	printf("递归法 快速排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void quickSort_test2()//非递归算法
{
	int arr[] = { 4, 3, 2, 8, 0, 9, 7, 8, 5, 4, 8, 9, 5, 6, 4 };
	int n = sizeof(arr) / sizeof(int);
	int left = 0;
	int right = n - 1;
	quick_Sort2(arr, left, right);
	printf("非递归法 快速排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void MergeSort_test1()
{
	int arr[] = { 4, 3, 2, 8, 0, 9, 7, 8, 5, 4, 8, 9, 5, 6, 4 };
	int n = sizeof(arr) / sizeof(int);
	int left = 0;
	int right = n - 1;
	Merge_Sort1(arr, left, right);
	printf("递归法 归并排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void MergeSort_test2()
{
	int arr[] = { 4, 3, 2, 8, 0, 9, 7, 8, 5, 4, 8, 9, 5, 6, 4 };
	int n = sizeof(arr) / sizeof(int);
	int left = 0;
	int right = n - 1;
	Merge_Sort2(arr, left, right);
	printf("非递归法 归并排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void CountSort_test()
{
	int arr[] = { 4, 3, 2, 8, 0, 9, 7, 8, 5, 4, 8, 9, 5, 6, 4 };
	int n = sizeof(arr) / sizeof(int);
	int left = 0;
	int right = n - 1;
	CountSort(arr, left, right);
	printf("计数法排序结果：");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	InterSort_test();

	ShellSort_test();

	SlectSort_test();

	HeapSort_test();

	BubbleSort_test();

	quickSort_test1();
	quickSort_test2();

	MergeSort_test1();
	MergeSort_test2();

	CountSort_test();
	system("pause");
	return 0;
}