#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>

#define OK 1
#define ERROR 0

#define MAXSIZE 100

typedef int ElemType;

typedef struct triple {
	int i, j;
	ElemType e;
} triple;

typedef struct TSMatrix {
	triple Elem[MAXSIZE + 1];
	int mu, nu, tu;
} TSMatrix;