#include"SqList.h"
#include"LinkList.h"

int main() {
	// ���Ա�����
	/*SqList L;
	InitSqList(&L);
	ErgodicSqList(&L);
	printf("˳����ĳ���Ϊ��%d��\n", SqListLength(&L));

	for (int i = 1; i <= 10; i++) {
		InsertSqList(&L, i, rand() % 100 + 1);
	}
	ErgodicSqList(&L);
	printf("˳����ĳ���Ϊ��%d��\n", SqListLength(&L));

	DeleteSqList(&L, 4);
	ErgodicSqList(&L);
	printf("˳����ĳ���Ϊ��%d��\n", SqListLength(&L));

	GetNode(&L, 4);

	LocateSqList(&L, 4);

	DestroySqList(&L);
	ErgodicSqList(&L);
	printf("˳����ĳ���Ϊ��%d��\n", SqListLength(&L));

	return OK;*/

	// ����������
	LNode L;
	InitLinkList_H(&L);

	InsertList_Back(&L, 5);
	InsertList_Back(&L, 54);

	LinkListLength(&L);
}