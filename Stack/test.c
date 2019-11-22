#include"stack.h"
void TestStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);

	while (StackEmpty(&s))
	{
		printf("%d ", Stacktop(&s));
		StackPop(&s);
	}
	StackDestory(&s);
}
int main()
{
	TestStack();
	system("pause");
	return 0;
}