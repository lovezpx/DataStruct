#include"SLinkList.h"

// ��ʼ����̬����
Status InitSLinkList(SLinkList space) {
	for (int i = 0; i < MAXSIZE; i++)
		space[i].cur = i + 1;

	space[0].cur = space[1].cur;
	space[1].cur = 0;

	printf("��̬�����ʼ���ɹ���\n");

	return OK;
}

// ���䱸�������һ�����,�����±�
// ��Ϊ0����˵��������������
int MallocSLinkList(SLinkList space) {
	int i = space[0].cur;
	if (space[0].cur)				//�жϱ��������Ƿ�ǿ�
		space[0].cur = space[i].cur;//��������ͷָ��ָ��ڶ����ս��

	return i;						//���ص�һ���ս��
}

//���±�Ϊk�Ŀ��н����յ���������
void FreeSLinkList(SLinkList space, int i) {
	space[i].cur = space[0].cur;    //��������������k֮��
	space[0].cur = i;               //��k������������ͷ֮��
}

// ��ȡ��̬����ĳ���
int SLinkListLength(SLinkList space) {
	int length = 0;
	int i = space[1].cur;
	while (i) {
		length++;
		i = space[i].cur;
	}

	return length;
}

// �ھ�̬����ĵ�i��λ�ò���Ԫ��
Status InsertSLinkList(SLinkList space, int i, ElemType e) {
	if (i < 1 || i > SLinkListLength(space) + 1)
		exit(OVERFLOW);

	int j, k = 1;
	for (j = 0; j < i - 1; j++) 
		k = space[k].cur;

	int v = MallocSLinkList(space);
	if (v) {
		space[v].data = e;
		space[v].cur = space[k].cur;
		space[k].cur = v;           //��������
	}

	return OK;
}

// ɾ����̬����ĵ�i��λ��
Status DeleteSLinkList(SLinkList space, int i) {
	if (i < 1 || i>SLinkListLength(space))
		exit(OVERFLOW);

	int j, k = 1;
	for (j = 0; j < i - 1; j++)
		k = space[k].cur;

	int temp = space[k].cur;
	space[k].cur = space[temp].cur;

	FreeSLinkList(space, temp);

	return OK;
}

// ������̬����
Status ErgodicSLinkList(SLinkList space) {
	int i = space[1].cur;
	int idx = 1;
	while (i)
	{
		printf("�� %d ��Ԫ���� %d��\n", idx++, space[i].data);
		i = space[i].cur;
	}

	return OK;
}