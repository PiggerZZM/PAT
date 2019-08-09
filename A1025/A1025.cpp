#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

struct Student
{
    char reg_num[13];
    int final_rank;
    int loc_num;
    int local_rank;
    int mark;
}stu[30010];

bool cmp(Student stu1, Student stu2)
{
    if(stu1.mark != stu2.mark)
        return stu1.mark > stu2.mark;
    else
        return strcmp(stu1.reg_num,stu2.reg_num) < 0;
    
}

int main()
{
    int n;
    scanf("%d",&n);
    int count = 0;
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            scanf("%s %d",stu[j+count].reg_num,&stu[j+count].mark);
            stu[j+count].loc_num = i;
        }
        sort(stu+count,stu+count+k,cmp);
        stu[count].local_rank = 1;
        for(int j=1;j<k;j++)
        {
            if(stu[count+j].mark == stu[count+j-1].mark)
                stu[count+j].local_rank = stu[count+j-1].local_rank;
            else
                stu[count+j].local_rank = j + 1;
        }
        count += k;
    }
    sort(stu,stu+count,cmp);
    stu[0].final_rank = 1;
    for(int i=1;i<count;i++)
    {
        if(stu[i].mark == stu[i-1].mark)
            stu[i].final_rank = stu[i-1].final_rank;
        else
            stu[i].final_rank = i + 1;
    }
    printf("%d\n",count);
    for(int i=0;i<count;i++)
        printf("%s %d %d %d\n",stu[i].reg_num,stu[i].final_rank,stu[i].loc_num,stu[i].local_rank);

    return 0;
}