#include"SArray.h"

Status InitArray(SArray *A, int dim, ...) {
	// 若维度dim和各维度长度合法，则构造相应的数组A，并返回OK
	if (dim<1 || dim>MAX_ARRAY_DIM)
		return ERROR;
	A->dim = dim;

	A->bounds = (int *)malloc(dim * sizeof(int));
	if (!A->bounds)
		exit(OVERFLOW);

	// 若各维长度合法，则存入A.bounds,并求出A的元素总数elemtotl
	int elemtotal = 1;// elemtotal是数组元素总数，初值为1(累乘器)  
	va_list ap;
	va_start(ap,dim);// 读取可变参数的过程其实就是在堆栈中，使用指针,遍历堆栈段中的参数列表,从低地址到高地址一个一个地把参数内容读出来的过程
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

	// 求映像函数的常数Ci，并存入A.constant[i-1],i=1,...,dim
	A->constants = (int *)malloc(dim * sizeof(int));
	if (!A->constants)
		exit(OVERFLOW);

	A->constants[dim - 1] = 1;// L=1,指针的增减以元素的大小为单位
	for (int i = dim - 2; i >= 0; i--) {
		A->constants[i] = A->bounds[i + 1] * A->constants[i + 1];
	}

	printf("顺序数组初始化成功！\n");
	return OK;
}

Status Locate(SArray *A, va_list ap, int *off) {
	// 若ap指示的各下标值合法，则求出该元素在A中相对地址off
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
	// A是n维数组，e为元素变量，随后是n个下标值 
	// 若各下标不超界，则e赋值为所指定的A的元素值，并返回OK
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
	// A是n维数组，e为元素变量，随后是n个下标值  
	// 若下标不越界，则将e的值赋值给所指定的A的元素，并返回OK  
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

	printf("顺序数组销毁成功！\n");
	return OK;
}