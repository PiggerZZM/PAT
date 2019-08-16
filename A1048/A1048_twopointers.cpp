#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int i = 0, j = n - 1;
    bool flag = 1;
    while (i < j)
    {
        if (a[i] + a[j] == m)
        {
            printf("%d %d\n", a[i], a[j]);
            flag = 0;
            break;
        }
        else if (a[i] + a[j] < m)
            i++;
        else
            j--;
    }

    if (flag)
        printf("No Solution\n");

    return 0;
}