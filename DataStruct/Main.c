#include"SqList.h"
#include"LinkList.h"
#include"SLinkList.h"
#include"DuLinkList.h"
#include"SqStack.h"
#include"SString.h"
#include"SArray.h"
#include"STriple.h"

int main() {
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

	PutLinkList(L, 2, 39);

	ListPrint(L);

	DeleteLinkList(L, 3);*/


}