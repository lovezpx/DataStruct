#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define OVERFLOW 0

#define MAXSIZE 10

typedef char SString[MAXSIZE];

typedef struct {
	char ch[MAXSIZE];
	int length;
} SqString;

typedef struct {
	char *ch;
	int length;
} HString;