#include"SString.h"

HString InitString() {
	HString s;
	s.length = 0;
	s.ch = (char *)malloc(STRING_INIT_SIZE * sizeof(char));
	s.strsize = STRING_INIT_SIZE;

	printf("字符串初始化成功！\n");
	return s;
}

int StrLength(HString s) {
	int length = s.length;
	printf("字符串的长度是：%d。\n", length);
	return length;
}