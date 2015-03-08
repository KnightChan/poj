#include<iostream>

using namespace std;

int n,k,ans=0,q[15000001],d[2000001];
bool f[2000001];

void bfs()
{
    int l=0,r=1,temp;
    ans=0;
    d[n]=0;
    q[1]=n;
    f[n]=true;
    while (l<r)
    {
        l++;
        temp=q[l];
        //cout<<ans<<","<<temp<<":";
        int t[3]={temp<<1,temp+1,temp-1};
        for (int i=0;i<3;i++)
        if (t[i]>=0&&!f[t[i]])
        {
            f[t[i]]=true;
            d[t[i]]=d[temp]+1;
            r++;q[r]=t[i];
          //  cout<<t[i]<<' ';
            if (t[i]==k)
            {
                ans=d[t[i]];
                return;
            }
        }
        //cout<<endl;
    }
}

int main()
{
    cin>>n>>k;
    memset(f,0,sizeof(f));
    if (n>=k)
    {
        cout<<n-k<<endl;
        return 0;
    }
    bfs();
    cout<<ans<<endl;
    return 0;
}
