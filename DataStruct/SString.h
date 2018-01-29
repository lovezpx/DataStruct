#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define OK 1
#define ERROR 0
#define OVERFLOW 0

#define STRING_INIT_SIZE 10
#define LISTINCREMENT 5

// 数组形式的串
typedef char SString[STRING_INIT_SIZE];

// 定长串
typedef struct {
	char ch[STRING_INIT_SIZE];
	int length;
} SqString;

// 动态顺序串
typedef struct {
	char *ch;
	int length;
	int strsize;
} HString;

// 初始化顺序串
HString InitString();
// 求串长
int StrLength(HString s);