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
// 判断空串
int isEmpty(HString s);
// 串打印
void StrPrint(HString s);
// 串赋值
void StrAssign(HString *s, char ch[]);
// 串拷贝
void StrCopy(HString *s1, HString s2);
// 串连接
void Concat(HString *s, HString s1, HString s2);
// 取子串
void SubString(HString *sn, HString s, int idx, int len);
// 插入串
void insertStr(HString *sn, int idx, HString s);