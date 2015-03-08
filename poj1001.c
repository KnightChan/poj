#include<iostream>
#include<string>
using namespace std;
int a[6],b[201],c[201],n;
string s;
void ca()
{
    int i,j;
    memset(c,0,sizeof(c));
    for (i=1;i<=a[0];++i)
    for (j=1;j<=b[0];++j)
    c[i+j-1]=a[i]*b[j]+c[i+j-1];
    c[0]=a[0]+b[0]-1;
    for (i=1;i<c[0];i++)
    {
        c[i+1]=c[i]/10+c[i+1];
        c[i]=c[i]%10;
    }
    while (c[c[0]]>=10)
    {
        c[c[0]+1]=c[c[0]]/10+c[c[0]+1];
        c[c[0]]=c[c[0]]%10;
        ++c[0];
    }
    while (c[c[0]]==0)--c[0];
    memset(b,0,sizeof(b));
    for (i=1;i<=c[0];i++) b[i]=c[i];
    b[0]=c[0];
}
void init()
{
    int i=6,k=0,m=0;
    while (i>0)
    {
        --i;
        if (s[i]=='.') k=5-i;
        else
        {
            m++;
            a[m]=s[i]-48;
        }
    }
    k*=n;
    b[1]=1;b[0]=1;
    a[0]=5;
    while (a[a[0]]==0) --a[0];
    for (i=0;i<n;i++) ca();
    m=1;
    while (c[m]==0)m++;
    if (c[0]<k)
    {
        cout<<'.';
        for (i=1;i<=k-c[0];i++) cout<<0;
        for (i=c[0];i>=m;i--) cout<<c[i];
        cout<<endl;
    }
    else
    {
        for (i=c[0];i>k;i--) cout<<c[i];
        if (k<m){ cout<<endl;return;}
        cout<<'.';
        for (i=k;i>=m;i--) cout<<c[i];
        cout<<endl;
    }

}
int main()
{
    while (cin>>s>>n)
    {
        init();
    }
    return 0;
}
