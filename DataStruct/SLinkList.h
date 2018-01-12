#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define OVERFLOW 0

#define MAXSIZE 10

typedef int ElemType;
typedef int Status;

typedef struct SLinkList {
	ElemType data;
	int cur;
} SLinkList[MAXSIZE];

Status InitSLinkList(SLinkList space);
int MallocSLinkList(SLinkList space);
void FreeSLinkList(SLinkList space, int i);
int SLinkListLength(SLinkList space);
Status InsertSLinkList(SLinkList space, int i, ElemType e);
Status DeleteSLinkList(SLinkList space, int i);
Status ErgodicSLinkList(SLinkList space);