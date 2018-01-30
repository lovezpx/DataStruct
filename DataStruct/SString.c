#include"SString.h"

// 初始化顺序串
HString InitString() {
	HString s;
	s.length = 0;
	s.ch = (char *)malloc(STRING_INIT_SIZE * sizeof(char));
	s.strsize = STRING_INIT_SIZE;

	printf("字符串初始化成功！\n");
	return s;
}

// 求串长
int StrLength(HString s) {
	int length = s.length;
	printf("字符串的长度是：%d。\n", length);
	return length;
}

// 判断空串
int isEmpty(HString s) {
	if (s.length == 0) {
		printf("字符串为空。\n");
		return 1;
	}
	else {
		printf("字符串不为空。\n");
		return 0;
	}
}

// 串打印
void StrPrint(HString s) {
	int i = s.length;
	if (i == 0)
		printf("串为空\n");
	for (i = 0; i < s.length; i++){
		printf("%c", *(s.ch + i));
	}
}