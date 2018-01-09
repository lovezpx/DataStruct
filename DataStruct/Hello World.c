#include <stdio.h>
#include<stdlib.h>
#include <malloc.h>

#define LIST_INIT_SIZE 10
#define LISTINCREMENT 5

#define OK 1
#define ERROR 0
#define OVERFLOW 0

typedef int Status;
typedef int ElemType;

typedef struct SqList {
	ElemType *elem;
	int length;
	int listsize;
} SqList;

// ��ʼ��˳���
Status InitSqList(SqList *L) {
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem)
		exit(OVERFLOW);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;

	return OK;
}

// �ںϷ�λ�ò���һ��Ԫ��
Status InsertSqList(SqList *L, int i, ElemType e) {
	if (i<1 || i > L->length + 1)
		return ERROR;
	if (L->length >= L->listsize) {
		ElemType *newBase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newBase)
			exit(OVERFLOW);
		L->elem = newBase;
		L->listsize += LISTINCREMENT;
	}

	ElemType *q = &(L->elem[i - 1]);
	for (ElemType *p = &(L->elem[L->length - 1]); p >= q; p--) {
		*(p + 1) = *p;
	}

	*q = e;
	L->length += 1;

	return OK;
}

// ����˳������Ƿ����ĳԪ�أ���������ӡλ��
Status LocateSqList(SqList *L, ElemType e) {
	for (int i = 0; i < L->length; i++) {
		if (L->elem[i] == e) {
			printf("�����Ա��в��ҵ�Ԫ�أ�Ԫ��λ�ã���%d��",i+1);
			printf("\n");
			return OK;
		}
	}
	printf("�����Ա���δ���ҵ���%d��Ԫ��", e);
	printf("\n");
	return OK;
}

// ��ȡ�ƶ�λ��Ԫ��
Status GetNode(SqList *L, int i) {
	if (i < 1 || i > L->length)
		exit(OVERFLOW);

	printf("˳���ڡ�%d��λ�ϵ�Ԫ���ǣ���%d��", i,L->elem[i - 1]);
	printf("\n");
}

// ɾ���ƶ�λ��Ԫ��
Status DeleteSqList(SqList *L, int i) {
	if (i < 1 || i > L->length)
		exit(OVERFLOW);
	ElemType *q = &(L->elem[i - 1]);
	ElemType *p = &(L->elem[L->length - 1]);
	for (q,p; q < p; q++) {
		*(q) = *(q + 1);
	}

	L->length -= 1;

	return OK;
}

// ����˳���
Status DestroySqList(SqList *L) {
	if (L->elem) {
		free(L->elem);

		L->elem = NULL;
		L->length = L->listsize = NULL;

		printf("���Ա����ٳɹ�");
		printf("\n");
	}
	
	return OK;
}

// ��ȡ˳�����
Status GetSqListLength(SqList *L) {
	if (L->elem) {
		if (L->length >= 0) {
			printf("˳�����Ϊ����%d��",L->length);
			printf("\n");
		}
		else {
			return ERROR;
		}
	}
	return OK;
}

// ����˳���
void ErgodicSqList(SqList *L) {
	if (!L->elem) {
		printf("˳���Ϊ�գ�");
		printf("\n");
		return;
	}

	for (int i = 1; i <= L->length; i++) {
		printf("�� %d ��Ԫ�ص�ֵ�ǣ���%d��", i, L->elem[i - 1]);
		printf("\n");
	}
}

void main() {
	SqList L;
	InitSqList(&L);

	InsertSqList(&L, 1, 2);
	InsertSqList(&L, 2, 3);
	InsertSqList(&L, 3, 4);
	InsertSqList(&L, 4, 5);
	InsertSqList(&L, 5, 6);
	InsertSqList(&L, 6, 7);
	InsertSqList(&L, 7, 8);
	InsertSqList(&L, 8, 9);
	InsertSqList(&L, 9, 10);
	InsertSqList(&L, 10, 11);

	//LocateSqList(&L, 4);

	//DestroySqList(&L);

	//GetNode(&L, 4);

	ErgodicSqList(&L);

	DeleteSqList(&L, 4);

	ErgodicSqList(&L);
}