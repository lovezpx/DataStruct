#include"LinkList.h"

// 单链表初始化(包含头结点)
Status InitLinkList_H(LinkList Head) {
	LinkList L = (LNode *)malloc(sizeof(LNode));
	if (!L) {
		printf("单链表初始化失败！\n");
		exit(OVERFLOW);
	}
	
	L->next = NULL;
	Head->next = L;

	printf("单链表初始化(包含头结点)初始化成功！\n");
	return OK;
}

// 单链表初始化(无头结点)
Status InitLinkList(LinkList Head){
	Head->next = NULL;

	printf("单链表初始化(无头结点)初始化成功！\n");
	return OK;
}

// 尾插法
Status InsertList_Back(LinkList L, ElemType e) {
	if (!L) {
		printf("单链表未初始化！\n");
		exit(OVERFLOW);
	}

	LinkList p = L;
	while (p->next)
		p = p->next;

	LinkList q = (LNode *)malloc(sizeof(LNode));
	q->data = e;
	q->next = NULL;

	p->next = q;

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
	while (q) {
		q = q->next;
		++count;
	}

	printf("单链表的长度是：%d。\n", count);
	return count;
}