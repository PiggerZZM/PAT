#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int a[100010];
vector<int> pivot;
bool left[100010] = {false};

int main()
{
    int n;
    int count = 0;
    int max = 0;
    int min = 0x7FFFFFFF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            left[i] = true;
        }
    }
    for (int j = n - 1; j >= 0; j--)
    {
        if (a[j] < min)
        {
            min = a[j];
            if (left[j])
            {
                pivot.push_back(a[j]);
                count++;
            }
        }
    }
    sort(pivot.begin(), pivot.end());

    printf("%d\n", count);
    for (int i = 0; i < count - 1; i++)
        printf("%d ", pivot[i]);
    if(count > 0)
        printf("%d\n", pivot[count - 1]);
    else
        printf("\n");

    return 0;
}