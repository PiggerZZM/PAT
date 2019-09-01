#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool isprime(int x)
{
    if(x == 1)
        return false;
    if(x == 2)
        return true;
    for(int i=2; i<x; i++)
        if(x % i == 0)
            return false;
    return true;

}

int main()
{
    int n,d;
    vector<int> rev;
    while(true)
    {
        scanf("%d",&n);
        if(n < 0)
            break;
        scanf("%d",&d);
        if(isprime(n))
        {
            rev.clear();
            while(n != 0)
            {
                int temp = n % d;
                rev.push_back(temp);
                n /= d;
            }
            int r = 0;
            vector<int>::iterator it;
            for(it = rev.begin(); it != rev.end(); it++)
                r = r * d + *it;
            if(isprime(r))
                printf("Yes\n");
            else
                printf("No\n");
        }
        else
            printf("No\n");
    }

    return 0;
}
