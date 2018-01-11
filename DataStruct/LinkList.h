#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW 0

typedef int ElemType;
typedef int Status;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

Status InitLinkList_H(LinkList L);
Status InsertList_Back(LinkList L, ElemType e);
int LinkListLength(LinkList L);
Status InsertList_Pre(LinkList L, ElemType e);
Status InsertLinkList(LinkList L, int i, ElemType e);
ElemType DeleteLinkList(LinkList L, int i);