#include <cstdio>

int a[7] = {66, 12, 33, 57, 64, 27, 18};

void merge(int a[], int left, int right, int mid, int n)
{
    int temp[100];
    for (int i = 0; i < n; i++)
        temp[i] = a[i];
    int i = 0, j = mid + 1, count = 0;
    while (i <= mid && j <= right)
    {
        if (temp[i] < temp[j])
            a[count++] = temp[i++];
        else
            a[count++] = temp[j++];
    }
    while (i <= mid)
        a[count++] = temp[i++];
    while (j <= right)
        a[count++] = temp[j++];
}

void mergesort(int a[], int left, int right, int n)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergesort(a, left, mid, n);
        mergesort(a, mid + 1, right, n);
        merge(a, left, right, mid, n);
    }
}

int main()
{
    mergesort(a, 0, 6, 7);

    for (int i = 0; i < 7; i++)
        printf("%d ", a[i]);

    return 0;
}