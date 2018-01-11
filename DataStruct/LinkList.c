#include"LinkList.h"

// �������ʼ��(����ͷ���)
Status InitLinkList_H(LinkList Head) {
	LinkList L = (LNode *)malloc(sizeof(LNode));
	if (!L) {
		printf("�������ʼ��ʧ�ܣ�\n");
		exit(OVERFLOW);
	}
	
	L->next = NULL;
	Head->next = L;

	printf("�������ʼ��(����ͷ���)��ʼ���ɹ���\n");
	return OK;
}

// �������ʼ��(��ͷ���)
Status InitLinkList(LinkList Head){
	Head->next = NULL;

	printf("�������ʼ��(��ͷ���)��ʼ���ɹ���\n");
	return OK;
}

// β�巨
Status InsertList_Back(LinkList L, ElemType e) {
	if (!L) {
		printf("������δ��ʼ����\n");
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

// ��������
int LinkListLength(LNode *L) {
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