#include"Heap.h"
void Heap_test()
{
	Heap ht;
	HpDataType a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HeapInit(&ht, a, sizeof(a) / sizeof(a[0]));

   //HeapPush(&ht, 1);
   //HeapPush(&ht, 2);
	
	//Heapsort(&ht);
	//HeapPop(&ht);
	//HeapPop(&ht);

	//printf("%d ", HeapTop(&ht));

	//printf("%d ", HeapSize(&ht));

	HeapPrint(&ht);

	HeapDestory(&ht);

	printf("%d ", HeapEmpty(&ht));
}
int main()
{
	Heap_test();
	system("pause");
	return 0;
}
