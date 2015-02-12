#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "misc.h"

char p[13]="a test word!";

static int m_strlen(const char* str)
{
    const char *eos=str;
    // 1. �쳣���
    assert(str!=0);
    // 2. ������λ����\0����
    while (*eos++);
    // 3. ����ֵΪ\0ǰ�ĳ���
    return eos-str-1;
}

static char *reverse(char* p)
{
    char *left=p;
    char *right=p;
    // �������һ����ĸ��'\0'ǰ
    while (*(right+1))
        right++;
    while(left < right)
    {
        char tmp = *left;
        *left++ = *right;
        *right-- = tmp;
    }
    return p;
}

static char *m_strcpy(char *dst, const char *src)
{
	// ��ָ����
	assert(dst!=NULL);
	assert(src!=NULL);
	// ָ���ص����
	memcpy(dst, src, strlen(src)+1);
	return dst;
}

void string()
{
	char tmp[13];
    printf("\nString:\n");
    printf("strlen: %d\n", strlen(p));
    printf("m_strlen: %d\n", m_strlen(p));
    printf("reverse: %s\n", reverse(p));
	printf("strcpy: %s\n", m_strcpy(tmp, p));
}