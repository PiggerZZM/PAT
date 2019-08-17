#include <cstdio>
#include <algorithm>
using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

bool cmp(int a[], int b[], int n)
{
    int i = 0;
    while (a[i] == b[i])
        i++;
    if (i == n)
        return true;
    else
        return false;
}

int main()
{
    int n;
    int a[100], b[100], temp[100];
    bool last = false;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i < n; i++)
        temp[i] = a[i];
    for (int i = 0; i < n - 1; i++)
    {
        int temp = a[i + 1];
        int j = i;
        while (a[j] > temp && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;

        if (last)
        {
            for (int i = 0; i < n - 1; i++)
                printf("%d ", a[i]);
            printf("%d\n", a[n - 1]);
            break;
        }

        if (cmp(a, b, n))
        {
            printf("Insertion Sort\n");
            last = true;
        }
    }

    if (!last)
    {
        printf("Merge Sort\n");
        for (int step = 2; step / 2 <= n; step *= 2)
        {
            for (int i = 0; i < n; i += step)
            {
                sort(temp + i, temp + min(i + step, n));
            }
            if (last)
            {
                for (int i = 0; i < n - 1; i++)
                    printf("%d ", temp[i]);
                printf("%d\n", temp[n - 1]);
                break;
            }

            if (cmp(temp, b, n))
                last = true;
        }
    }
    return 0;
}