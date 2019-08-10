#include <cstdio>

int main()
{
    int x;
    char ch[4];
    x = 1;
    scanf("%s", ch);
    printf("%d\n",x);

    int *p = &x;
    printf("%p,%p",p,ch);
    return 0;
}