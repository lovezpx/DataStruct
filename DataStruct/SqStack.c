#include"SqStack.h"

// ��ʼ��ջ
Status InitSqStack(SqStack *L) {
	L->base = L->top = (ElemType *)malloc(INIT_STACK_SIZE * sizeof(ElemType));
	if (!L->base || !L->top)
		exit(OVERFLOW);

	L->stacksize = INIT_STACK_SIZE;

	printf("˳��ջ��ʼ���ɹ�~\n");

	return OK;
}

// ��ȡջ��Ԫ��
Status GetTop(SqStack *L) {
	if (L->top == L->base)
		exit(OVERFLOW);

	ElemType e = *(L->top - 1);

	printf("ջ��Ԫ�ص�ֵΪ��%d��\n", e);

	return OK;
}

// 
Status Push(SqStack *L, ElemType e) {
	if ((L->top - L->base) >= L->stacksize) {
		ElemType *newspace = (ElemType *)realloc(L->base, (L->stacksize + STACKINCREMENT) * sizeof(ElemType));
		if (!newspace)
			exit(OVERFLOW);

		L->base = newspace;

		L->top = L->base + L->stacksize;
		L->stacksize = L->stacksize + STACKINCREMENT;
	}

	*L->top++ = e;

	return OK;
}