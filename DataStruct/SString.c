#include"SString.h"

HString InitString() {
	HString s;
	s.length = 0;
	s.ch = (char *)malloc(STRING_INIT_SIZE * sizeof(char));
	s.strsize = STRING_INIT_SIZE;

	printf("�ַ�����ʼ���ɹ���\n");
	return s;
}

int StrLength(HString s) {
	int length = s.length;
	printf("�ַ����ĳ����ǣ�%d��\n", length);
	return length;
}