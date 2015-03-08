#include<iostream>
#include<string.h>
using namespace std;

const int M = 10001;
int prime[M], sum[M];
int count = 0;
bool f[M];
int ans[M];


int main()
{
    int k = 2;
    memset(f, 0, sizeof(f));
    prime[count ++] = 0;
    for (int i = 2;i < M;i ++)
    if (f[i] == false)
    {
        k = i;
        //cout<<k<<" ";
        prime[count ++] = k;
        while ((k + i) < M) {
            k += i;
            f[k] = true;
        }
    }
    sum[0] = prime[0];
    for (int i = 1;i < count;i ++)
    {
        sum[i] = sum[i - 1] + prime[i];
        //cout<<sum[i]<<" ";
    }
    memset(ans, 0, sizeof(ans));

    for (int i = 0;i < count - 1;i ++)
    for (int j = i + 1;j < count;j ++)
    if (sum[j] - sum[i] < M)
        ans[sum[j] - sum[i]] ++;
    int t;
    cin>>t;
    while (t)
    {
        cout<<ans[t]<<endl;
        cin>>t;
    }
    return 0;
}
