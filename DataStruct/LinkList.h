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
	struct Lnode *next;
} LNode, *LinkList;

Status InitLinkList(LNode *L);
int LinkListLength(LNode *L);