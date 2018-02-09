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
	ElemType *base;// �����ַ
	int dim;       // ����ά��
	int *bounds;   // ����ά�ȵĵ�ַ
	int *constants;// ����ӳ����������ַ�����Ϊ��ά�ȵ�Ȩ�ء�(b2*b3*...*bn) = constants[0]��
} SArray;

// ��ʼ��˳������
Status InitArray(SArray *A, int dim, ...);
// ����˳������
Status DestroyArray(SArray *A);
// ��Ԫ���������е����λ��
Status Locate(SArray *A, va_list ap, int *off);
// ȡֵ
ElemType Value(SArray *A, ElemType e, ...);
// ��ֵ
Status Assign(SArray *A, ElemType e, ...);