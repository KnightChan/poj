#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1000001;
int a, b, sum[N];
char csum[N];
int n;

int main()
{
    cin>>n;
    for (int i = 0;i < n;i ++)
    {
        scanf("%d%d", &a, &b);
        sum[i] = a + b;
    }
    for (int i = n - 1;i > 0;i --)
    {
        if (sum[i] >= 10)
        {
            sum[i - 1] ++;
            sum[i] -= 10;
        }
        csum[i] = sum[i] + '0';
        //printf("%c",csum[i]);
    }
    csum[0] = sum[0] + '0';
    csum[n] = '\0';
    //for (int i = 0;i < n;i ++)
    //    printf("%d",sum[i]);
    //cout<<endl;
    printf("%s\n", csum);
    return 0;
}
