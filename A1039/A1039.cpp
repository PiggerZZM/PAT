#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int namesize = 4;

int hashtable(char ch[])
{
    int result = 0;
    for (int i = 0; i < namesize - 1; i++)
    {
        result *= 26;
        result += (ch[i] - 'A');
    }
    result *= 10;
    result += (ch[namesize - 1] - '0');

    return result;
}

vector<int> stu[26 * 26 * 26 * 10 + 10];

int main()
{
    int n, k;
    int stu_num;
    int stu_id;
    int course;
    char stu_name[namesize+1];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &course, &stu_num);
        for (int j = 0; j < stu_num; j++)
        {
            scanf("%s", stu_name);
            stu_id = hashtable(stu_name);
            stu[stu_id].push_back(course);
        }
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%s", stu_name);
        stu_id = hashtable(stu_name);
        sort(stu[stu_id].begin(), stu[stu_id].end());
        int size = stu[stu_id].size();
        printf("%s %d", stu_name, size);
        for (int j = 0; j < size; j++)
            printf(" %d", stu[stu_id][j]);
        printf("\n");
    }

    return 0;
}