#include"SString.h"

// ��ʼ��˳��
HString InitString() {
	HString s;
	s.length = 0;
	s.ch = (char *)malloc(STRING_INIT_SIZE * sizeof(char));
	s.strsize = STRING_INIT_SIZE;

	printf("�ַ�����ʼ���ɹ���\n");
	return s;
}

// �󴮳�
int StrLength(HString s) {
	int length = s.length;
	printf("�ַ����ĳ����ǣ�%d��\n", length);
	return length;
}

// �жϿմ�
int isEmpty(HString s) {
	if (s.length == 0) {
		printf("�ַ���Ϊ�ա�\n");
		return 1;
	}
	else {
		printf("�ַ�����Ϊ�ա�\n");
		return 0;
	}
}

// ����ӡ
void StrPrint(HString s) {
	int i = s.length;
	if (i == 0)
		printf("��Ϊ��\n");
	for (i = 0; i < s.length; i++){
		printf("%c", *(s.ch + i));
	}

	printf("\n");
}

// ����ֵ
void StrAssign(HString *s, char ch[]) {
	int i = 0;
	while (ch[i] != '\0') {
		i++;
	}

	if (i > s->strsize) {
		s->ch = (char *)malloc(i * sizeof(char));
		s->strsize = i;
	}

	s->length = i;

	for (i = 0; i < s->length; i++) {
		s->ch[i] = ch[i];
	}

	printf("�ַ�����ֵ�ɹ���\n");
}

// ������
void StrCopy(HString *s1, HString s2) {
	if (s1->strsize < s2.length) {
		s1->ch = (char*)realloc(s1->ch, s2.length * sizeof(char));
		s1->strsize = s2.length;
	}

	int i;
	for (i = 0; i < s2.length; i++) {
		s1->ch[i] = s2.ch[i];
	}

	s1->length = s2.length;

	printf("�ַ�����ֵ�ɹ���\n");
}

// ������
void Concat(HString *s, HString s1, HString s2) {
	if (s->strsize < s1.length + s2.length) {
		s->ch = (char *)realloc(s->ch, (s1.length + s2.length) * sizeof(char));
		s->strsize = s1.length + s2.length;
	}

	int i;
	for (i = 0; i < s1.length; i++) {
		s->ch[i] = s1.ch[i];
	}
		
	for (i; i < s1.length + s2.length; i++) {
		s->ch[i] = s2.ch[i - s1.length];
	}

	s->length = s1.length + s2.length;

	printf("�ַ������ӳɹ���\n");
}

// ȡ�Ӵ�
void SubString(HString *sn, HString s, int idx, int len) {
	if (idx <= 0 || idx > s.length || len < 0 || len > s.length - idx + 1) {
		exit(OVERFLOW);
	}

	if (sn->length < len) {
		sn->ch = (char *)realloc(sn->ch, len * sizeof(char));
		sn->strsize = len;
	}

	int i;
	for (i = 0; i < len; i++) {
		sn->ch[i] = s.ch[idx - 1 + i];
	}

	sn->length = len;

	printf("�ַ���ȡ�Ӵ��ɹ���\n");
}

// ���봮
void insertStr(HString *sn, int idx, HString s) {
	if (idx <= 0 || idx > sn->length + 1) {
		exit(OVERFLOW);
	}

	if (sn->strsize < sn->length + s.length) {
		sn->ch = (char *)realloc(sn->ch, (sn->length + s.length) * sizeof(char));
		sn->strsize = sn->length + s.length;
	}

	int i;
	for (i = sn->length - 1; i >= idx - 1; i--) {
		sn->ch[i + s.length] = sn->ch[i];
	}

	for (i = 0; i < s.length; i++) {
		sn->ch[i + idx - 1] = s.ch[i];
	}

	sn->length = sn->length + s.length;

	printf("�ַ�������ɹ���\n");
}

// ��ɾ��
void deleteStr(HString *s, int idx, int len) {
	if (idx <= 0 || idx > s->length || len < 0 || len > s->length - idx + 1) {
		exit(OVERFLOW);
	}

	int i;
	for (i = idx + len - 1; i < s->length; i++) {
		s->ch[i - len] = s->ch[i];
	}

	s->length -= len;

	printf("�ַ���ɾ���ɹ���\n");
}

// ����Brute-Force�㷨
void BFIndex(HString S, HString T, int pos) {
	if (pos < 0 || pos > S.length - T.length + 1) {
		exit(OVERFLOW);
	}

	int i = pos - 1, j = 0;
	while (i < S.length && j < T.length) {
		if (S.ch[i] == T.ch[j]) {
			++i;
			++j;
		} else {
			i = i - j + 1;
			j = 0;
		}
	}

	if (j == T.length) {
		printf("�ַ���ƥ��ɹ���λ���ǣ�%d��\n", i - T.length + 1);
		return i - T.length + 1;
	}

	printf("�ַ���ƥ��ʧ�ܣ�\n");
}