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

static void reverse2new(const char *src, char *dst)
{
	int i = 0;
	int len = strlen(src);
	//dst = (char *)malloc(len+1);
	for (i = 0; i < len; i++)
	{
		dst[i] = src[i];
	}
	dst[i]='\0';
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
		// swap(left, right), left++, right--
        char tmp = *left;
        *left++ = *right;
        *right-- = tmp;
    }
    return p;
}

static char *m_strcpy(char *dst, const char *src)
{
	// 空指针检查
	assert(dst!=NULL);
	assert(src!=NULL);
	// 指针重叠检查
	memcpy(dst, src, strlen(src)+1);
	return dst;
}

#define INT_MIN     (-2147483647 - 1)
#define INT_MAX     2147483647

int atoi(const char *str)
{
	int i = 0, base = 0, sign = 1;
	// 0. 跳过空格
	while(str[i]==' ') i++;
	// 1. 符号转换
	if (str[i]=='-' || str[i]=='+')
	{
		sign = 1 - 2 * str[i++]=='-';
	}
	// 2. 数字转换
	while (str[i] > '0' && str[i] < '9')
	{
		// 2.1 越界检查
		if (str[i] > INT_MAX || (str[i] == INT_MAX && (str[i] % 10 > 7)))
		{
			if (sign==1) return INT_MAX;
			else return INT_MIN;
		}
		// 2.2 转换
		base = 10 * base + str[i++] - '0';
	}
	// 3. 加符号位返回
	return base*sign;
}

static char* loop_move(char *str)
{
	int len = strlen(str+1);
	char *tmp = (char *)malloc(len);
	int i=0;
	for (i=0; i < len; i++)
	{
		tmp[i] = str[(i + 2)%len];
	}
	tmp[i]='\0';
	return tmp;
}

static int last_str_length(char *str)
{
	int len=0;
	while(*str)
	{
		if (*str++ != ' ')
			len++;
		else if(*str && *str != ' ')
			len = 0;
	}
	return len;
}

static void tolower(const char *src, char *dst)
{
	while(*src)
	{
		if ((*src >= 'A' && *src <= 'Z') || (*src >= 'a' && *src <= 'z'))
		{
			if (*src >= 'A' && *src <= 'Z')
			{
				*dst++ = *src++ + 32;
			}
			else
			{
				*dst++ = *src++;
			}
		}
		else
		{
			src++;
		}
	}
	*dst = '\0';
}

void string()
{
	char tmp[13]={0};
    printf("\nString:\n");
    printf("strlen: %d\n", strlen(p));
    printf("m_strlen: %d\n", m_strlen(p));
	reverse2new("abc def gggg", tmp);
	printf("reverse2new: %s\n", tmp);
    printf("reverse: %s\n", reverse(p));
	printf("strcpy: %s\n", m_strcpy(tmp, p));
	printf("atoi: %d\n", atoi(" -34"));
	printf("loop_move: %s\n", loop_move("abcdef"));
	printf("last_str_length: %d\n", last_str_length("abc def gggg"));
	tolower("ABC Def Gggg", tmp);
	printf("tolower: %s\n", tmp);
}