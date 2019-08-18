#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

char stu[40000][5];

vector<int> course[2500];

bool cmp(int n1, int n2)
{
    return strcmp(stu[n1], stu[n2]) < 0;
}

int main()
{
    int n, k;
    char name[5];
    int num;
    int course_index;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", name, &num);
        strcpy(stu[i],name);
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &course_index);
            course[course_index - 1].push_back(i);
        }
    }

    for (int i = 0; i < k; i++)
    {
        num = course[i].size();
        sort(course[i].begin(), course[i].end(), cmp);
        printf("%d %d\n", i + 1, num);
        for (int j = 0; j < num; j++)
            printf("%s\n", stu[course[i][j]]);
    }

    return 0;
}