#include <cstdio>
#include <algorithm>
using namespace std;

struct Student
{
    int id;
    int GE;
    int GI;
    double grade;
    int choice[5];
    int rank;
} stu[40010], stu1[40010];

struct School
{
    int quota;
    int num_of_stu;
    int student[40010];
} sch[110];

bool cmp(Student s1, Student s2)
{
    if (s1.grade != s2.grade)
        return s1.grade > s2.grade;
    else
        return s1.GE > s2.GE;
}

bool cmp1(Student s1, Student s2)
{
    return s1.id < s2.id;
}

int main()
{
    int n, m, k;
    int temp1, temp2;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &sch[i].quota);
        sch[i].num_of_stu = 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &temp1, &temp2);
        stu[i].GE = temp1;
        stu[i].GI = temp2;
        stu[i].grade = 0.5 * (temp1 + temp2);
        stu[i].id = i;
        for (int j = 0; j < k; j++)
            scanf("%d", &stu[i].choice[j]);
    }
    sort(stu, stu + n, cmp);
    
    stu[0].rank = 0;
    for (int i = 1; i < n; i++)
    {
        if (stu[i].grade == stu[i - 1].grade && stu[i].GE == stu[i - 1].GE)
            stu[i].rank = stu[i - 1].rank;
        else
            stu[i].rank = i;
    }

    for (int i = 0; i < n; i++)
    {
        stu1[i].id = stu[i].id;
        stu1[i].rank = stu[i].rank;
    }
    sort(stu1, stu1 + n, cmp1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int choice_school = stu[i].choice[j];
            if (sch[choice_school].quota != 0)
            {
                if (sch[choice_school].num_of_stu < sch[choice_school].quota)
                {
                    sch[choice_school].student[sch[choice_school].num_of_stu++] = stu[i].id;
                    break;
                }
                else
                {
                    int temp_id = sch[choice_school].student[sch[choice_school].quota - 1];
                    if (stu[i].rank == stu1[temp_id].rank)
                    {
                        sch[choice_school].student[sch[choice_school].num_of_stu++] = stu[i].id;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < m; i++)
        sort(sch[i].student, sch[i].student + sch[i].num_of_stu);

    for (int i = 0; i < m; i++)
    {
        int tmp = sch[i].num_of_stu;
        if (tmp != 0)
        {
            printf("%d", sch[i].student[0]);
            for (int j = 1; j < tmp; j++)
                printf(" %d", sch[i].student[j]);
            printf("\n");
        }
        else
            printf("\n");
    }

    return 0;
}