#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define OVERFLOW 0

#define STRING_INIT_SIZE 10
#define LISTINCREMENT 5

// ������ʽ�Ĵ�
typedef char SString[STRING_INIT_SIZE];

// ������
typedef struct {
	char ch[STRING_INIT_SIZE];
	int length;
} SqString;

// ��̬˳��
typedef struct {
	char *ch;
	int length;
	int strsize;
} HString;

// ��ʼ��˳��
HString InitString();
// �󴮳�
int StrLength(HString s);