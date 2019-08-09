#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Record
{
    char id[10];
    char name[10];
    int grade;
}rec[100010];

bool cmp1(Record r1, Record r2)
{
    return strcmp(r1.id,r2.id) < 0;
}

bool cmp2(Record r1, Record r2)
{
    if(strcmp(r1.name,r2.name) != 0)
        return strcmp(r1.name,r2.name) < 0;
    else
        return strcmp(r1.id,r2.id) < 0;
}

bool cmp3(Record r1, Record r2)
{
    if(r1.grade != r2.grade)
        return r1.grade < r2.grade;
    else
        return strcmp(r1.id,r2.id) < 0;
}

int main()
{
    int n,c;
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;i++)
        scanf("%s %s %d",rec[i].id,rec[i].name,&rec[i].grade);
    switch (c)
    {
    case 1:
        sort(rec,rec+n,cmp1);
        break;
    case 2:
        sort(rec,rec+n,cmp2);
        break;
    case 3:
        sort(rec,rec+n,cmp3);
        break;
    }
    for(int i=0;i<n;i++)
        printf("%s %s %d\n",rec[i].id,rec[i].name,rec[i].grade);

    return 0;
}