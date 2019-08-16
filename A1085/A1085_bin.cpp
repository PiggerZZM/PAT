#include <cstdio>
#include <algorithm>
using namespace std;

long long a[100010];

int bin(long long a[], int left, int right, long long x)
{
    int mid;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(a[mid] > x)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main()
{
    int n,num = 0;
    long long m,p;
    int last;
    scanf("%d %lld",&n,&p);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        m = a[i];
        last = bin(a,i,n,m*p) - 1;
        if(num < last - i + 1)
            num = last - i + 1;
    }

    printf("%d\n",num);

    return 0;
}