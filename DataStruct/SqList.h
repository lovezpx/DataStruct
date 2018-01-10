#pragma once

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

extern void InitSqList(SqList *L);
extern void ErgodicSqList(SqList *L);
extern int SqListLength(SqList *L);
extern Status InsertSqList(SqList *L, int i, ElemType e);
extern Status DeleteSqList(SqList *L, int i);
extern Status GetNode(SqList *L, int i);
extern Status LocateSqList(SqList *L, ElemType e);
extern Status DestroySqList(SqList *L);