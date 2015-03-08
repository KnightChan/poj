#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
struct Node
{
    string s;
    int ans;
};
int i,j,n,k,m;
Node a[101];
void swap(int i,int j)
{
    Node t=a[i];
    a[i]=a[j];
    a[j]=t;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
    {
        //scanf("%s",a[i].s);
        cin>>a[i].s;
        a[i].ans=0;
        for (j=0;j<n-1;j++)
        for (k=j+1;k<=n-1;k++)
        if (a[i].s[j]>a[i].s[k]) a[i].ans++;
    }
    for (i=1;i<m;i++)
    for (j=i+1;j<=m;j++)
    if (a[i].ans>a[j].ans)
    swap(i,j);
    for (i=1;i<=m;i++) cout<<a[i].s<<endl;
    //printf("%s\n",a[i].s);//ดํมห!
    return 0;
}
