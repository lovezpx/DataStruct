#include"SqList.h"
#include"LinkList.h"
#include"SLinkList.h"
#include"DuLNode.h"
#include"SqStack.h"
#include"SString.h"

int main() {
	// ˳�򴮲���
	/*HString s = InitString();
	StrAssign(&s,"lovezpx");
	StrLength(s);
	isEmpty(s);
	StrPrint(s);

	HString sc = InitString();
	StrCopy(&sc, s);
	StrPrint(sc);

	HString sn = InitString();
	Concat(&sn, s, sc);
	StrPrint(sn);

	HString sz = InitString();
	SubString(&sz, sn, 2, 5);
	StrPrint(sz);

	insertStr(&s, 3, sz);
	StrPrint(s);

	deleteStr(&s, 2, 5);
	StrPrint(s);

	// Brute-Force�㷨
	HString S = InitString();
	StrAssign(&S, "lovpxhflovezpxw");
	StrPrint(S);

	HString T = InitString();
	StrAssign(&T, "lovezpx");
	StrPrint(T);

	BFIndex(S,T,1);

	// KMP�㷨
	HString S = InitString();
	StrAssign(&S, "abaabbaacabaabcacabcaac");
	StrPrint(S);

	HString T = InitString();
	StrAssign(&T, "abaabcac");
	StrPrint(T);

	//KMPIndex(S, T);

	KMPIndex_New(S, T);*/

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