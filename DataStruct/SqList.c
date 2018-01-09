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

int main() {
	SqList L;
	InitSqList(&L);
	ErgodicSqList(&L);
	printf("顺序表的长度为：%d。\n",SqListLength(&L));

	for (int i = 1; i <= 10; i++) {
		InsertSqList(&L, i, rand() % 100 + 1);
	}
	ErgodicSqList(&L);
	printf("顺序表的长度为：%d。\n", SqListLength(&L));

	DeleteSqList(&L, 4);
	ErgodicSqList(&L);
	printf("顺序表的长度为：%d。\n", SqListLength(&L));

	return OK;
}

void InitSqList(SqList *L) {
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem)
		exit(OVERFLOW);

	L->length = 0;
	L->listsize = LIST_INIT_SIZE;

	printf("顺序表初始化成功~\n");
}

// 遍历顺序表
void ErgodicSqList(SqList *L) {
	if (!L)
		exit(OVERFLOW);

	if (L->length == 0) {
		printf("顺序表为空！\n");
		return;
	}

	for (int i = 1; i <= L->length; i++) {
		printf("顺序表第 %d 个元素的值是：%d。\n",i,L->elem[i-1]);
	}
}

// 获取顺序表长度
int SqListLength(SqList *L) {
	if (L->elem)
		return L->length;
	else
		return ERROR;
}

// 在合法位置插入一个元素
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

// 删除制定位置元素
Status DeleteSqList(SqList *L, int i) {
	if (i < 1 || i > L->length + 1)
		return ERROR;

	ElemType *q = &(L->elem[L->length - 1]);
	for (ElemType *p = &(L->elem[i - 1]); p < q; p++)
		*p = *(p + 1);

	-- L->length;

	return OK;
}