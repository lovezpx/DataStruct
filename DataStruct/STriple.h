#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define OVERFLOW 0

#define TRIPLE_INIT_SIZE 100

typedef int ElemType;

typedef struct triple {
	int i, j;
	ElemType Elem;
} triple;

typedef struct TSMatrix {
	triple Elem[TRIPLE_INIT_SIZE];
	int EPos[TRIPLE_INIT_SIZE];
	int n, m, num;
} TSMatrix;

typedef struct OLNode {
	int i, j;
	int data;
	struct OLNode * right, *down;
} OLNode;

typedef struct {
	OLNode * rhead, *chead;
	int n, m, num;
}CrossList;