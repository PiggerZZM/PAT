#include <cstdio>
#include <algorithm>
using namespace std;

int tonum(int digit[])
{
    int ans = 0;
    for (int i = 0; i < 4; i++)
        ans = ans * 10 + digit[i];
    return ans;
}

int *todigit(int num)
{
    int* digit = new int[4];
    for (int i = 3; i >= 0; i--)
    {
        digit[i] = num % 10;
        num /= 10;
    }
    return digit;
}

bool cmp(int n1, int n2)
{
    return n1 > n2;
}

int main()
{
    int *digit1, *digit2;
    int num;
    scanf("%d", &num);
    do
    {
        int num1, num2;
        digit1 = todigit(num);
        sort(digit1, digit1 + 4, cmp);
        digit2 = todigit(num);
        sort(digit2, digit2 + 4);
        num1 = tonum(digit1);
        num2 = tonum(digit2);
        num = num1 - num2;
        printf("%04d - %04d = %04d\n",num1,num2,num);
    } while(num != 0 && num != 6174);

    return 0;
}