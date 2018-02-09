#include"SqList.h"
#include"LinkList.h"
#include"SLinkList.h"
#include"DuLNode.h"
#include"SqStack.h"
#include"SString.h"
#include"SArray.h"
#include"STriple.h"

int main() {
	SArray *A = (SArray *)malloc(sizeof(SArray));
	InitArray(A, 2, 5, 6);

	Assign(A, 3, 2, 4);

	ElemType e;
	printf("坐标[%d,%d]的值是：%d", 2, 4, Value(A, &e, 2, 4));

	//DestroyArray(A);
} 