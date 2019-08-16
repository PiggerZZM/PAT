#include <cstdio>
#include <algorithm>
using namespace std;

long long a[100010];

int main()
{
    int n;
    long long p;
    scanf("%d %lld", &n, &p);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sort(a, a + n);
    int num = 1;
    int count;
    int i = 0, j = 0;
    while (j < n && i < n)
    {
        long long temp = a[i] * p;
        while (temp >= a[j] && j < n)
            j++;
        count = j - i;
        if (count > num)
            num = count;
        i++;
    }

    printf("%d\n", num);

    return 0;
}