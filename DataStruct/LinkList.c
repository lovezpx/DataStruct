#include"LinkList.h"

// 单链表初始化(包含头结点)
LinkList InitLinkList_H() {
	LinkList L = (LNode *)malloc(sizeof(LNode));
	if (!L) {
		printf("单链表初始化失败！\n");
		exit(OVERFLOW);
	}
	
	L->next = NULL;

	printf("单链表初始化(包含头结点)初始化成功！\n");
	return L;
}

// 单链表初始化(无头结点)
LinkList InitLinkList() {
	LinkList L = NULL;

	printf("单链表初始化(无头结点)初始化成功！\n");
	return L;
}

// 尾插法
Status InsertList_Back(LinkList L, ElemType e) {
	LinkList p = L;
	while (p->next)
		p = p->next;

	LinkList q = (LNode *)malloc(sizeof(LNode));
	q->data = e;
	q->next = NULL;

	p->next = q;

	return OK;
}

// 头插法
Status InsertList_Pre(LinkList L, ElemType e) {
	LinkList q = (LNode *)malloc(sizeof(LNode));
	if (!q) {
		printf("节点空间申请失败！\n");
		exit(OVERFLOW);
	}

	LinkList head = L;
	q->next = head->next;
	head->next = q;

	q->data = e;

	return OK;
}

// 单链表长度
int LinkListLength(LinkList L) {
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

// 在第i位置上插入元素
Status InsertLinkList(LinkList L, int i, ElemType e) {
	LinkList p = L;
	
	int idx = 1;
	while(idx < i) {
		p = p->next;
		idx++;
	}

	LinkList q = (LNode *)malloc(sizeof(LNode));
	q->data = e;
	q->next = p->next;

	p->next = q;

	return OK;
}

// 删除第i位置上的元素
ElemType DeleteLinkList(LinkList L, int i) {
	LinkList p = L;

	int idx = 1;
	while (idx < i) {
		p = p->next;
		idx++;
	}

	LinkList q = p->next;
	ElemType elem = q->data;
	p->next = q->next;

	free(q);

	return elem;
}