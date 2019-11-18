#include"SList.h"
void Slist_Test()
{
	Slist  cb;
	Slist_Int(&cb);
	SList_Tail_Insert(&cb, 1);
	SList_Tail_Insert(&cb, 2);
	SList_Tail_Insert(&cb, 2);
	SList_Tail_Insert(&cb, 3);
	SList_Tail_Insert(&cb, 4);
	SList_Tail_Insert(&cb, 5);
	
	Slist_Tail_Delete(&cb);
	Slist_Head_Insert(&cb, 2);
	Slist_Head_Delete(&cb);
	Slist_Print(&cb);

	SlistNode* pos = Slist_Find(&cb,1);
	Slist_Insert_After(pos,25);

	SlistNode* pos1 = Slist_Find(&cb, 3);
	Slist_Insert_After(pos1, 25);

	Slist_Erase_After(pos);

	Slist_Remove(&cb, 2);

	SlistNode* pos3 = Slist_Find(&cb, 3);
	Slist_Insert_Front(&cb,pos3,55);

	Slist_All_Remove(&cb, 2);

	Slist_Print(&cb);
}
int main()
{
	Slist_Test();
	system("pause");
	return 0;
}
