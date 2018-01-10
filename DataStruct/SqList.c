#include"SqList.h"

// 初始化顺序表
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

// 获取制定位置元素
Status GetNode(SqList *L, int i) {
	if (i < 1 || i > L->length)
		exit(OVERFLOW);

	printf("顺序表第 %d 位上的元素是：%d。\n", i, L->elem[i - 1]);
	printf("\n");

	return OK;
}

// 查找顺序表中是否存在某元素，如存在则打印位置
Status LocateSqList(SqList *L, ElemType e) {
	for (int i = 0; i < L->length; i++) {
		if (L->elem[i] == e) {
			printf("在线性表中查找到元素，元素位置：%d。\n", i + 1);
			return OK;
		}
	}

	printf("在线性表中未查找到【%d】元素！\n", e);

	return OK;
}

// 销毁顺序表
Status DestroySqList(SqList *L) {
	if (L->elem) {
		free(L->elem);

		L->elem = NULL;
		L->length = L->listsize = 0;

		printf("线性表销毁成功！\n");
	}

	return OK;
}