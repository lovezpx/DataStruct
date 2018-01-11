#include"LinkList.h"

// �������ʼ��(����ͷ���)
LinkList InitLinkList_H() {
	LinkList L = (LNode *)malloc(sizeof(LNode));
	if (!L) {
		printf("�������ʼ��ʧ�ܣ�\n");
		exit(OVERFLOW);
	}
	
	L->next = NULL;

	printf("�������ʼ��(����ͷ���)��ʼ���ɹ���\n");
	return L;
}

// �������ʼ��(��ͷ���)
LinkList InitLinkList() {
	LinkList L = NULL;

	printf("�������ʼ��(��ͷ���)��ʼ���ɹ���\n");
	return L;
}

// β�巨
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

// ͷ�巨
Status InsertList_Pre(LinkList L, ElemType e) {
	LinkList q = (LNode *)malloc(sizeof(LNode));
	if (!q) {
		printf("�ڵ�ռ�����ʧ�ܣ�\n");
		exit(OVERFLOW);
	}

	LinkList head = L;
	q->next = head->next;
	head->next = q;

	q->data = e;

	return OK;
}

// ��������
int LinkListLength(LinkList L) {
	if (!L) {
		printf("������δ��ʼ����\n");
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

	printf("������ĳ����ǣ�%d��\n", count);
	return count;
}

// �ڵ�iλ���ϲ���Ԫ��
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

// ɾ����iλ���ϵ�Ԫ��
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