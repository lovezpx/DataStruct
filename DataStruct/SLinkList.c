#include"SLinkList.h"

// 初始化静态链表
Status InitSLinkList(SLinkList space) {
	for (int i = 0; i < MAXSIZE; i++)
		space[i].cur = i + 1;

	space[0].cur = space[1].cur;
	space[1].cur = 0;

	printf("静态链表初始化成功！\n");

	return OK;
}

// 分配备用链表的一个结点,返回下标
// 若为0，则说明备用链表用完
int MallocSLinkList(SLinkList space) {
	int i = space[0].cur;
	if (space[0].cur)				//判断备用链表是否非空
		space[0].cur = space[i].cur;//备用链表头指针指向第二个空结点

	return i;						//返回第一个空结点
}

//将下标为k的空闲结点回收到备用链表
void FreeSLinkList(SLinkList space, int i) {
	space[i].cur = space[0].cur;    //将备用链表链到k之后
	space[0].cur = i;               //将k链到备用链表头之后
}

// 获取静态链表的长度
int SLinkListLength(SLinkList space) {
	int length = 0;
	int i = space[1].cur;
	while (i) {
		length++;
		i = space[i].cur;
	}

	return length;
}

// 在静态链表的第i个位置插入元素
Status InsertSLinkList(SLinkList space, int i, ElemType e) {
	if (i < 1 || i > SLinkListLength(space) + 1)
		exit(OVERFLOW);

	int j, k = 1;
	for (j = 0; j < i - 1; j++) 
		k = space[k].cur;

	int v = MallocSLinkList(space);
	if (v) {
		space[v].data = e;
		space[v].cur = space[k].cur;
		space[k].cur = v;           //链入链表
	}

	return OK;
}

// 删除静态链表的第i个位置
Status DeleteSLinkList(SLinkList space, int i) {
	if (i < 1 || i>SLinkListLength(space))
		exit(OVERFLOW);

	int j, k = 1;
	for (j = 0; j < i - 1; j++)
		k = space[k].cur;

	int temp = space[k].cur;
	space[k].cur = space[temp].cur;

	FreeSLinkList(space, temp);

	return OK;
}

// 遍历静态链表
Status ErgodicSLinkList(SLinkList space) {
	int i = space[1].cur;
	int idx = 1;
	while (i)
	{
		printf("第 %d 个元素是 %d。\n", idx++, space[i].data);
		i = space[i].cur;
	}

	return OK;
}