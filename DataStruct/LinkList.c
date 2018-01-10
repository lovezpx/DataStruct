#include"LinkList.h"

// 单链表初始化
Status InitLinkList(LNode *L) {
	L = (LNode *)malloc(sizeof(LNode));
	if (!L) {
		printf("单链表初始化失败！\n");
		exit(OVERFLOW);
	}

	L->next = NULL;

	printf("单链表初始化成功！\n");
	return OK;
}

// 单链表长度
int LinkListLength(LNode *L) {
	if (!L) {
		printf("单链表未初始化！\n");
		exit(OVERFLOW);
	}

	int count = 0;
	LinkList q = L;
	if (q)
		q = q->next;
	while (q)
		q = q->next;
		++count;

	return count;
}