#include"SqList.h"
#include"LinkList.h"
#include"SLinkList.h"
#include"DuLNode.h"
#include"SqStack.h"
#include"SString.h"

int main() {
	// ˳�򴮲���
	HString s = InitString();
	StrLength(s);
	isEmpty(s);

	// ���Ա����
	/*SqList L;
	InitSqList(&L);
	ErgodicSqList(&L);
	printf("˳���ĳ���Ϊ��%d��\n", SqListLength(&L));

	for (int i = 1; i <= 10; i++) {
		InsertSqList(&L, i, rand() % 100 + 1);
	}
	ErgodicSqList(&L);
	printf("˳���ĳ���Ϊ��%d��\n", SqListLength(&L));

	DeleteSqList(&L, 4);
	ErgodicSqList(&L);
	printf("˳���ĳ���Ϊ��%d��\n", SqListLength(&L));

	GetNode(&L, 4);

	LocateSqList(&L, 4);

	DestroySqList(&L);
	ErgodicSqList(&L);
	printf("˳���ĳ���Ϊ��%d��\n", SqListLength(&L));

	return OK;*/

	// ���������
	/*LinkList L = InitLinkList_H();

	InsertList_Back(L, 5);
	InsertList_Back(L, 54);

	InsertList_Pre(L, 46);

	LinkListLength(L);

	InsertLinkList(L, 2, 39);

	DeleteLinkList(L, 3);*/

	// ��̬�������
	/*SLinkList space;
	InitSLinkList(space);

	printf("��̬����ĳ��ȣ�%d��\n", SLinkListLength(space));

	InsertSLinkList(space, 1, rand() % 100 + 1);

	printf("��̬����ĳ��ȣ�%d��\n", SLinkListLength(space));

	InsertSLinkList(space, 2, rand() % 100 + 1);

	printf("��̬����ĳ��ȣ�%d��\n", SLinkListLength(space));

	DeleteSLinkList(space, 2);

	ErgodicSLinkList(space);*/

	// ˫�������
	/*DuLinkList *L = InitDuLinkList();

	InsertDuList_Pre(L, 5);

	InsertDuList_Back(L, 8);*/

	// ˳��ջ����
	/*SqStack L;
	InitSqStack(&L);

	Push(&L, rand() % 100 + 1);
	Push(&L, rand() % 100 + 1);
	Push(&L, rand() % 100 + 1);

	GetTop(&L);*/
}