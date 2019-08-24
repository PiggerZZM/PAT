#include <cstdio>
#include <algorithm>
using namespace std;

int ins[100], heap[100];
int target[100];

void siftdown(int first, int last)
{
    int temp = heap[first];
    int i = 2 * first;
    while (i <= last)
    {
        if (i + 1 <= last && heap[i + 1] > heap[i])
            i = i + 1;
        if (temp < heap[i])
        {
            heap[first] = heap[i];
            first = i;
            i = 2 * first;
        }
        else
            break;
    }
    heap[first] = temp;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        ins[i] = heap[i + 1] = temp;
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &target[i]);

    bool last = false;
    for (int i = 0; i < n - 1; i++)
    {
        int temp = ins[i + 1];
        int j;
        for (j = i + 1; j > 0; j--)
        {
            if (ins[j - 1] > temp)
                ins[j] = ins[j - 1];
            else
                break;
        }
        ins[j] = temp;
        if (last)
        {
            printf("Insertion Sort\n");
            for (int k = 0; k < n - 1; k++)
                printf("%d ", ins[k]);
            printf("%d\n", ins[n - 1]);
            break;
        }

        int k;
        for (k = 0; k < n; k++)
            if (ins[k] != target[k])
                break;
        if (k == n)
            last = true;
    }

    if (!last)
    {
        for (int i = n; i >= 1; i--)
            siftdown(i, n);
        for (int i = n; i > 1; i--)
        {
            swap(heap[1],heap[i]);
            siftdown(1, i-1);
            if (last)
            {
                printf("Heap Sort\n");
                for (int k = 1; k <= n - 1; k++)
                    printf("%d ", heap[k]);
                printf("%d\n", heap[n]);
                break;
            }
            int k;
            for (k = 1; k <= n; k++)
                if (heap[k] != target[k - 1])
                    break;
            if (k == n + 1)
                last = true;
        }
    }

    return 0;
}