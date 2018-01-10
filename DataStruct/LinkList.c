#include"LinkList.h"

// �������ʼ��
Status InitLinkList(LNode *L) {
	L = (LNode *)malloc(sizeof(LNode));
	if (!L) {
		printf("�������ʼ��ʧ�ܣ�\n");
		exit(OVERFLOW);
	}

	L->next = NULL;

	printf("�������ʼ���ɹ���\n");
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
	while (q)
		q = q->next;
		++count;

	return count;
}