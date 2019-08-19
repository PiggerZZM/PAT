#include <cstdio>

struct Node
{
    char letter;
    int next;
    bool flag;
}node[100010];

int main()
{
    int p1,p2,n;
    scanf("%d %d %d",&p1,&p2,&n);
    int add,next;
    char ch;
    bool find = false;
    for(int i=0;i<n;i++)
    {
        scanf("%d %c %d",&add,&ch,&next);
        node[add].letter = ch;
        node[add].next = next;
    }

    while(p1 != -1)
    {
        node[p1].flag = true;
        p1 = node[p1].next;
    }

    while(p2 != -1)
    {
        if(node[p2].flag)
        {
            printf("%05d\n",p2);
            find = true;
            break;
        }
        p2 = node[p2].next;
    }

    if(!find)
        printf("-1\n");

    return 0;
}