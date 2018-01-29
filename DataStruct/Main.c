#include"SqList.h"
#include"LinkList.h"
#include"SLinkList.h"
#include"DuLNode.h"
#include"SqStack.h"
#include"SString.h"

int main() {
	// 顺序串测试
	HString s = InitString();
	StrLength(s);
	isEmpty(s);

	// 线性表测试
	/*SqList L;
	InitSqList(&L);
	ErgodicSqList(&L);
	printf("顺序表的长度为：%d。\n", SqListLength(&L));

	for (int i = 1; i <= 10; i++) {
		InsertSqList(&L, i, rand() % 100 + 1);
	}
	ErgodicSqList(&L);
	printf("顺序表的长度为：%d。\n", SqListLength(&L));

	DeleteSqList(&L, 4);
	ErgodicSqList(&L);
	printf("顺序表的长度为：%d。\n", SqListLength(&L));

	GetNode(&L, 4);

	LocateSqList(&L, 4);

	DestroySqList(&L);
	ErgodicSqList(&L);
	printf("顺序表的长度为：%d。\n", SqListLength(&L));

	return OK;*/

	// 单链表测试
	/*LinkList L = InitLinkList_H();

	InsertList_Back(L, 5);
	InsertList_Back(L, 54);

	InsertList_Pre(L, 46);

	LinkListLength(L);

	InsertLinkList(L, 2, 39);

	DeleteLinkList(L, 3);*/

	// 静态链表测试
	/*SLinkList space;
	InitSLinkList(space);

	printf("静态链表的长度：%d。\n", SLinkListLength(space));

	InsertSLinkList(space, 1, rand() % 100 + 1);

	printf("静态链表的长度：%d。\n", SLinkListLength(space));

	InsertSLinkList(space, 2, rand() % 100 + 1);

	printf("静态链表的长度：%d。\n", SLinkListLength(space));

	DeleteSLinkList(space, 2);

	ErgodicSLinkList(space);*/

	// 双链表测试
	/*DuLinkList *L = InitDuLinkList();

	InsertDuList_Pre(L, 5);

	InsertDuList_Back(L, 8);*/

	// 顺序栈测试
	/*SqStack L;
	InitSqStack(&L);

	Push(&L, rand() % 100 + 1);
	Push(&L, rand() % 100 + 1);
	Push(&L, rand() % 100 + 1);

	GetTop(&L);*/
}