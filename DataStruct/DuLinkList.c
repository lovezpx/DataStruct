#include"DuLinkList.h"

// ��ʼ��˫����
DuLinkList *InitDuLinkList() {
	DuLinkList *L = (DuLinkList *)malloc(sizeof(DuLinkList));
	if (!L)
		exit(OVERFLOW);

	L->head = (DuLNode *)malloc(sizeof(DuLNode));
	L->tail = (DuLNode *)malloc(sizeof(DuLNode));

	L->head->prior = NULL;
	L->head->next = L->tail;

	L->tail->next = NULL;
	L->tail->prior = L->head;

	L->length = 0;

	printf("˫�������ʼ���ɹ���\n");

	return L;
}

// ͷ�巨
Status InsertDuList_Pre(DuLinkList *L, ElemType e) {
	Position p = (DuLNode *)malloc(sizeof(DuLNode));
	if (!p)
		exit(OVERFLOW);

	p->data = e;

	p->prior = L->head;
	p->next = L->head->next;

	L->head->next->prior = p;
	L->head->next = p;

	L->length++;

	return OK;
}

//// β�巨
Status InsertDuList_Back(DuLinkList *L, ElemType e) {
	Position p = (DuLNode *)malloc(sizeof(DuLNode));
	if (!p)
		exit(OVERFLOW);

	p->data = e;

	p->prior = L->tail->prior;
	p->next = L->tail;

	L->tail->prior->next = p;
	L->tail ->prior = p;

	L->length++;

	return OK;
}