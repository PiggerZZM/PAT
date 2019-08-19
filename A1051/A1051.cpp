#include <cstdio>
#include <stack>
using namespace std;

int a[1010];

int main()
{
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    stack<int> s;
    bool flag;
    while(k--)
    {
        int N = 1;
        int current = 0;
        flag = false;
        for (int j = 0; j < n; j++)
            scanf("%d", &a[j]);
        while (s.size() != 0)
            s.pop();
        s.push(N++);
        while(N <= n+1)
        {
            if (s.size() != 0 && a[current] == s.top())
            {
                s.pop();
                current++;
                if(current == n)
                {
                    flag = true;
                    break;
                }
            }
            else if (s.size() >= m)
                break;
            else
                s.push(N++);
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
