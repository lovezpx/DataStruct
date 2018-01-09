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

// 初始化顺序表
Status InitSqList(SqList *L) {
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem)
		exit(OVERFLOW);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;

	return OK;
}

// 在合法位置插入一个元素
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

// 查找顺序表中是否存在某元素，如存在则打印位置
Status LocateSqList(SqList *L, ElemType e) {
	for (int i = 0; i < L->length; i++) {
		if (L->elem[i] == e) {
			printf("在线性表中查找到元素，元素位置：【%d】",i+1);
			printf("\n");
			return OK;
		}
	}
	printf("在线性表中未查找到【%d】元素", e);
	printf("\n");
	return OK;
}

// 获取制定位置元素
Status GetNode(SqList *L, int i) {
	if (i < 1 || i > L->length)
		exit(OVERFLOW);

	printf("顺序表第【%d】位上的元素是：【%d】", i,L->elem[i - 1]);
	printf("\n");
}

// 删除制定位置元素
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

// 销毁顺序表
Status DestroySqList(SqList *L) {
	if (L->elem) {
		free(L->elem);

		L->elem = NULL;
		L->length = L->listsize = NULL;

		printf("线性表销毁成功");
		printf("\n");
	}
	
	return OK;
}

// 获取顺序表长度
Status GetSqListLength(SqList *L) {
	if (L->elem) {
		if (L->length >= 0) {
			printf("顺序表长度为：【%d】",L->length);
			printf("\n");
		}
		else {
			return ERROR;
		}
	}
	return OK;
}

// 遍历顺序表
void ErgodicSqList(SqList *L) {
	if (!L->elem) {
		printf("顺序表为空！");
		printf("\n");
		return;
	}

	for (int i = 1; i <= L->length; i++) {
		printf("第 %d 个元素的值是：【%d】", i, L->elem[i - 1]);
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