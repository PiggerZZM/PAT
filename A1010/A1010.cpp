#include <cstdio>
#include <cstring>
#include <cstring>
using namespace std;

bool h[36] = {false};
const long long inf = 0x7FFFFFFF;

long long value(char ch[], long long radix)
{
    long long val = 0;
    int p = 0;
    char temp = ch[p];
    while (temp != '\0')
    {
        val *= radix;
        if (temp >= '0' && temp <= '9')
            val += (temp - '0');
        else if (temp >= 'a' && temp <= 'z')
            val += (temp - 'a' + 10);
        if (val < 0)
            return -1;
        p++;
        temp = ch[p];
    }
    return val;
}

long long bin(char n2[], long long left, long long right, long long val1)
{
    long long mid;
    long long val2;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        val2 = value(n2, mid);
        if (val2 == val1)
            return mid;
        else if (val2 < val1 && val2 > 0)
            left = mid + 1;
        else if(val2 > val1 || val2 < 0)
            right = mid - 1;
    }
    return -1;
}

int main()
{
    char n1[20], n2[20];
    long long min_radix = 2;
    int tag;
    long long radix;
    scanf("%s %s %d %lld", n1, n2, &tag, &radix);
    if (tag == 2)
    {
        char tmp[20];
        strcpy(tmp, n1);
        strcpy(n1, n2);
        strcpy(n2, tmp);
    }
    int len2 = strlen(n2);
    long long val1;

    for (int i = 0; i < len2; i++)
    {
        if (n2[i] <= '9' && n2[i] >= '0')
            h[n2[i] - '0'] = true;
        else if (n2[i] >= 'a' && n2[i] <= 'z')
            h[n2[i] - 'a' + 10] = true;
    }

    for (long long i = 0; i < 36; i++)
    {
        if (h[i])
            min_radix = i;
    }
    min_radix++;

    val1 = value(n1, radix);

    radix = bin(n2, min_radix, inf, val1);
    if (radix != -1)
        printf("%lld\n", radix);
    else
        printf("Impossible\n");

    return 0;
}