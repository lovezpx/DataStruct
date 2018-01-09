#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define LIST_INIT_SIZE 10
#define LISTINCREMENT 5

#define OK 1
#define ERROR 0
#define OVERFLOW 0

typedef int ElemType;
typedef int Status;

typedef struct SqList {
	ElemType *elem;
	int length;
	int listsize;
} SqList;

void InitSqList(SqList *L);
void ErgodicSqList(SqList *L);
int SqListLength(SqList *L);
Status InsertSqList(SqList *L, int i, ElemType e);
Status DeleteSqList(SqList *L, int i);
Status GetNode(SqList *L, int i);
Status LocateSqList(SqList *L, ElemType e);
Status DestroySqList(SqList *L);

int main() {
	SqList L;
	InitSqList(&L);
	ErgodicSqList(&L);
	printf("˳���ĳ���Ϊ��%d��\n", SqListLength(&L));

	for (int i = 1; i <= 10; i++) {
		InsertSqList(&L, i, rand() % 100 + 1);
	}
	ErgodicSqList(&L);
	printf("˳���ĳ���Ϊ��%d��\n", SqListLength(&L));

	DeleteSqList(&L, 4);
	ErgodicSqList(&L);
	printf("˳���ĳ���Ϊ��%d��\n", SqListLength(&L));

	GetNode(&L, 4);

	LocateSqList(&L, 4);

	DestroySqList(&L);
	ErgodicSqList(&L);
	printf("˳���ĳ���Ϊ��%d��\n", SqListLength(&L));

	return OK;
}

// ��ʼ��˳���
void InitSqList(SqList *L) {
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem)
		exit(OVERFLOW);

	L->length = 0;
	L->listsize = LIST_INIT_SIZE;

	printf("˳����ʼ���ɹ�~\n");
}

// ����˳���
void ErgodicSqList(SqList *L) {
	if (!L)
		exit(OVERFLOW);

	if (L->length == 0) {
		printf("˳���Ϊ�գ�\n");
		return;
	}

	for (int i = 1; i <= L->length; i++) {
		printf("˳���� %d ��Ԫ�ص�ֵ�ǣ�%d��\n",i,L->elem[i-1]);
	}
}

// ��ȡ˳�����
int SqListLength(SqList *L) {
	if (L->elem)
		return L->length;
	else
		return ERROR;
}

// �ںϷ�λ�ò���һ��Ԫ��
Status InsertSqList(SqList *L, int i, ElemType e) {
	if (i < 1 || i > L->length + 1)
		return ERROR;

	if (L->length >= L->listsize) {
		ElemType *newbase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
			exit(OVERFLOW);

		L->elem = newbase;
		L->listsize += LISTINCREMENT;
	}

	ElemType *q = &(L->elem[i - 1]);
	for (ElemType *p = &(L->elem[L->length - 1]); p >= q; p--)
		*(p + 1) = *p;

	*q = e;
	++ L->length;

	return OK;
}

// ɾ���ƶ�λ��Ԫ��
Status DeleteSqList(SqList *L, int i) {
	if (i < 1 || i > L->length + 1)
		return ERROR;

	ElemType *q = &(L->elem[L->length - 1]);
	for (ElemType *p = &(L->elem[i - 1]); p < q; p++)
		*p = *(p + 1);

	-- L->length;

	return OK;
}

// ��ȡ�ƶ�λ��Ԫ��
Status GetNode(SqList *L, int i) {
	if (i < 1 || i > L->length)
		exit(OVERFLOW);

	printf("˳���� %d λ�ϵ�Ԫ���ǣ�%d��\n", i, L->elem[i - 1]);
	printf("\n");
}

// ����˳������Ƿ����ĳԪ�أ���������ӡλ��
Status LocateSqList(SqList *L, ElemType e) {
	for (int i = 0; i < L->length; i++) {
		if (L->elem[i] == e) {
			printf("�����Ա��в��ҵ�Ԫ�أ�Ԫ��λ�ã�%d��\n", i + 1);
			return OK;
		}
	}

	printf("�����Ա���δ���ҵ���%d��Ԫ�أ�\n", e);

	return OK;
}

// ����˳���
Status DestroySqList(SqList *L) {
	if (L->elem) {
		free(L->elem);

		L->elem = NULL;
		L->length = L->listsize = NULL;

		printf("���Ա����ٳɹ���\n");
	}

	return OK;
}