#include <vector>
#include <cstdio>
using namespace std;

vector<char *> course[2500];

int main()
{
    int n = 2, k = 2;
    char name[5];
    int num;
    int course_index;
    /*scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", name, &num);
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &course_index);
            course[course_index - 1].push_back(name);
        }
    }*/
    scanf("%s",name);
    course[0].push_back(name);

    course[1].push_back("name");
        scanf("%s",name);
    course[0].push_back(name);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < course[i].size(); j++)
            printf("%s ", course[i][j]);
        putchar('\n');
    }

    return 0;
}