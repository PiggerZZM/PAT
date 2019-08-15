#include <cstdio>
#include <vector>
using namespace std;

vector<int> a;
const int inf = 0x7FFFFFFF;

int main()
{
    int n1,n2;
    int temp, median;
    int p1 = 0, p2 = 0,count = -1;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &temp);
        a.push_back(temp);
    }
    a.push_back(inf);
    scanf("%d", &n2);
    int mid = (n1 + n2 - 1) / 2;
    scanf("%d", &temp);
    while (p2 < n2 && count < mid)    // 因为设置了哨兵，第一个序列不可能读完，要么第二个序列没读完就找到中位数，要么第二个序列读完了还没找到中位数
    {
        if (temp < a[p1])
        {
            p2++;
            median = temp;
            scanf("%d", &temp);
        }
        else
        {
            p1++;
            median = a[p1 - 1];
        }
        count++;
    }
    while(count < mid)    // 第二个序列读完了还没找到中位数
    {
        median = a[p1++];
        count++;
    }

    printf("%d\n", median);

    return 0;
}