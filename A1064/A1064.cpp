#include <cstdio>
#include <algorithm>
using namespace std;
int bst[1000];
int n, c = 0;
int tmp[1000];

void inorder(int root)
{
    if (2 * root <= n)
        inorder(2 * root);
    bst[root] = tmp[c++];
    if (2 * root + 1 <= n)
        inorder(2 * root + 1);
}

int main()
{
    scanf("%d", &n);
    int temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        tmp[i] = temp;
    }
    sort(tmp, tmp + n);
    inorder(1);

    for (int i = 1; i < n; i++)
        printf("%d ", bst[i]);
    printf("%d\n", bst[n]);

    return 0;
}