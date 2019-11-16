#include"Dlist.h"
void List_test1()
{
	List cb;
	ListInt(&cb);
	ListHead_insert(&cb, 1);
	ListHead_insert(&cb, 2);
	ListHead_insert(&cb, 3);
	ListHead_insert(&cb, 4);
	ListHead_insert(&cb, 5);

	ListHead_delete(&cb);
	ListHead_delete(&cb);
	ListHead_delete(&cb);
	ListHead_delete(&cb);

	List_print(&cb);
}
void List_test2()
{
	List cb;
	ListInt(&cb);
	ListTail_insert(&cb, 1);
	ListTail_insert(&cb, 2);
	ListTail_insert(&cb, 3);
	ListTail_insert(&cb, 4);
	ListTail_insert(&cb, 5);


	ListTail_delete(&cb);
	ListTail_delete(&cb);
	ListTail_delete(&cb);
	ListTail_delete(&cb);

	List_print(&cb);

    ListNode* pos = List_find(&cb,1);
	ListFind_insert( pos, 5);
	List_print(&cb);

	ListNode* pos1 = List_find(&cb, 3);
	ListFind_delete(pos1);
	List_print(&cb);

	ListDestroy(&cb);
}
int main()
{
    //List_test1();
	List_test2();
	system("pause");
	return 0;
}