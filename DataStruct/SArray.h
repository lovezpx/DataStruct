#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdarg.h>
#include<math.h>

#define MAX_ARRAY_DIM 8

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;


typedef struct SArray {
	ElemType *base;// 数组基址
	int dim;       // 数组维数
	int *bounds;   // 数组维度的地址
	int *constants;// 数组映像函数常量基址，理解为各维度的权重【(b2*b3*...*bn) = constants[0]】
} SArray;

// 初始化顺序数组
Status InitArray(SArray *A, int dim, ...);
// 销毁顺序数组
Status DestroyArray(SArray *A);
// 求元素在数组中的相对位置
Status Locate(SArray *A, va_list ap, int *off);
// 取值
ElemType Value(SArray *A, ElemType e, ...);
// 赋值
Status Assign(SArray *A, ElemType e, ...);