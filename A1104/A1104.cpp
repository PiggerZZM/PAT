#include <cstdio>

double a[100010];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lf", &a[i]);

    double ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (a[i] * i * (n + 1 - i));

    printf("%.2f\n", ans);

    return 0;
}