#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define OVERFLOW 0

#define INIT_STACK_SIZE 10
#define STACKINCREMENT 5

typedef int ElemType;
typedef int Status;

typedef struct SqStack {
	ElemType *base;
	ElemType *top;

	int stacksize;
} SqStack;

Status InitSqStack(SqStack *L);
Status GetTop(SqStack *L);
Status Push(SqStack *L, ElemType e);