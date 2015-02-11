#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "misc.h"

char p[13]="a test word!";

static int m_strlen(const char* str)
{
    const char *eos=str;
    // 1. 异常检测
    assert(str!=0);
    // 2. 遍历后，位置在\0后面
    while (*eos++);
    // 3. 返回值为\0前的长度
    return eos-str-1;
}

static char *reverse(char* p)
{
    char *left=p;
    char *right=p;
    // 跳至最后一个字母，'\0'前
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

void string()
{
    printf("\nString:\n");
    printf("strlen: %d\n", strlen(p));
    printf("m_strlen: %d\n", m_strlen(p));
    printf("reverse: %s\n", reverse(p));
}
