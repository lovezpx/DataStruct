// 顺序串测试
HString s = InitString();
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

// Brute-Force算法
HString S = InitString();
StrAssign(&S, "lovpxhflovezpxw");
StrPrint(S);

HString T = InitString();
StrAssign(&T, "lovezpx");
StrPrint(T);

BFIndex(S,T,1);

// KMP算法
HString S = InitString();
StrAssign(&S, "abaabbaacabaabcacabcaac");
StrPrint(S);

HString T = InitString();
StrAssign(&T, "abaabcac");
StrPrint(T);

//KMPIndex(S, T);

KMPIndex_New(S, T);

// 静态链表测试
SLinkList space;
InitSLinkList(space);

printf("静态链表的长度：%d。\n", SLinkListLength(space));

InsertSLinkList(space, 1, rand() % 100 + 1);

printf("静态链表的长度：%d。\n", SLinkListLength(space));

InsertSLinkList(space, 2, rand() % 100 + 1);

printf("静态链表的长度：%d。\n", SLinkListLength(space));

DeleteSLinkList(space, 2);

ErgodicSLinkList(space);

// 双链表测试
DuLinkList *L = InitDuLinkList();

InsertDuList_Pre(L, 5);

InsertDuList_Back(L, 8);

// 顺序栈测试
SqStack L;
InitSqStack(&L);

Push(&L, rand() % 100 + 1);
Push(&L, rand() % 100 + 1);
Push(&L, rand() % 100 + 1);

GetTop(&L);

// 顺序数组测试
SArray *A = (SArray *)malloc(sizeof(SArray));
InitArray(A, 2, 5, 6);

Assign(A, 3, 2, 4);

ElemType e;
printf("坐标[%d,%d]的值是：%d", 2, 4, Value(A, &e, 2, 4));

DestroyArray(A);