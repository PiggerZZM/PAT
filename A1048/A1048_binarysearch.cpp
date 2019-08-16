#include <cstdio>
#include <algorithm>
using namespace std;
int coins[100010];

int binarysearch(int a[], int left, int right, int x)
{
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] > x)
            right = mid - 1;
        else if (a[mid] < x)
            left = mid + 1;
    }
    return -1;
}

int main()
{
    int n, m;
    int index;
    int flag = 1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);
    sort(coins, coins + n);
    for (int i = 0; i < n; i++)
    {
        index = binarysearch(coins, 0, n - 1, m - coins[i]);
        if (index != i && index != -1)
        {
            flag = 0;
            printf("%d %d\n", coins[i], coins[index]);
            break;
        }
    }
    if (flag)
        printf("No Solution\n");

    return 0;
}