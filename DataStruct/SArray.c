#include"SArray.h"

Status InitArray(SArray *A, int dim, ...) {
	// ��ά��dim�͸�ά�ȳ��ȺϷ���������Ӧ������A��������OK
	if (dim<1 || dim>MAX_ARRAY_DIM)
		return ERROR;
	A->dim = dim;

	A->bounds = (int *)malloc(dim * sizeof(int));
	if (!A->bounds)
		exit(OVERFLOW);

	// ����ά���ȺϷ��������A.bounds,�����A��Ԫ������elemtotl
	int elemtotal = 1;// elemtotal������Ԫ����������ֵΪ1(�۳���)  
	va_list ap;
	va_start(ap,dim);// ��ȡ�ɱ�����Ĺ�����ʵ�����ڶ�ջ�У�ʹ��ָ��,������ջ���еĲ����б�,�ӵ͵�ַ���ߵ�ַһ��һ���ذѲ������ݶ������Ĺ���
	for (int i = 0; i < dim; i++) {
		A->bounds[i] = va_arg(ap,int);
		if (A->bounds[i] < 0)
			return UNDERFLOW;
		elemtotal *= A->bounds[i];
	}
	va_end(ap);

	A->base = (ElemType *)malloc(elemtotal * sizeof(ElemType));
	if (!A->base)
		exit(OVERFLOW);

	// ��ӳ�����ĳ���Ci��������A.constant[i-1],i=1,...,dim
	A->constants = (int *)malloc(dim * sizeof(int));
	if (!A->constants)
		exit(OVERFLOW);

	A->constants[dim - 1] = 1;// L=1,ָ���������Ԫ�صĴ�СΪ��λ
	for (int i = dim - 2; i >= 0; i--) {
		A->constants[i] = A->bounds[i + 1] * A->constants[i + 1];
	}

	printf("˳�������ʼ���ɹ���\n");
	return OK;
}

Status Locate(SArray *A, va_list ap, int *off) {
	// ��apָʾ�ĸ��±�ֵ�Ϸ����������Ԫ����A����Ե�ַoff
	int ind;
	*off = 0;
	for (int i = 0; i < A->dim; i++) {
		ind = va_arg(ap, int);
		if (ind < 0 || ind >= A->bounds[i])
			return OVERFLOW;

		*off += A->constants[i] * ind;
	}

	return OK;
}

ElemType Value(SArray *A, ElemType e, ...) {
	// A��nά���飬eΪԪ�ر����������n���±�ֵ 
	// �����±겻���磬��e��ֵΪ��ָ����A��Ԫ��ֵ��������OK
	va_list ap;
	int result;
	int off = 0;
	va_start(ap, e);
	if ((result = Locate(A, ap, &off)) <= 0)
		return result;
	va_end(ap);

	e = *(A->base + off);

	return e;
}

Status Assign(SArray *A, ElemType e, ...) {
	// A��nά���飬eΪԪ�ر����������n���±�ֵ  
	// ���±겻Խ�磬��e��ֵ��ֵ����ָ����A��Ԫ�أ�������OK  
	va_list ap;
	va_start(ap, e);
	int off = 0;
	int result;
	if (result = Locate(A, ap, &off) <= 0)
		return result;
	*(A->base + off) = e;

	return OK;
}

Status DestroyArray(SArray *A) {
	if (!A->base)
		return ERROR;
	free(A->base);
	A->base = NULL;

	A->dim = NULL;

	if (!A->bounds)
		return ERROR;
	free(A->bounds);
	A->bounds = NULL;

	if (!A->constants)
		return ERROR;
	free(A->constants);
	A->constants = NULL;

	printf("˳���������ٳɹ���\n");
	return OK;
}