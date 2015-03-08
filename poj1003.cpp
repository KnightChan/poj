#include<iostream>
using namespace std;

int main()
{
    float a[301],b;
    int i=0,n;
    a[0]=0;
    while (a[i]<5.21)
    {
        a[i+1]=a[i]+1.0/(i+2);
        ++i;
    }
    cin>>b;
    n=i;
    while (b>0)
    {
        for (i=1;i<=n;++i)
        if ((b>a[i-1])&&(b<a[i])) cout<<i<<" card(s)"<<endl;
        cin>>b;
    }
    return 0;
}
