#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW 0

typedef int ElemType;
typedef int Status;

typedef struct DuLNode {
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
} DuLNode, *Position;

typedef struct DuLinkList {
	Position head, tail;
	int length;
} DuLinkList;

DuLinkList *InitDuLinkList();
Status InsertDuList_Pre(DuLinkList *L, ElemType e);
Status InsertDuList_Back(DuLinkList *L, ElemType e);