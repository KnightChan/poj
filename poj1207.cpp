#include<iostream>
using namespace std;

int c[10001];

int check(int x)
{
    int l=1;
    while (x!=1)
    {
        if (x%2) x=3*x+1;
        else x/=2;
        l++;
    }
    return l;
}

void swap(int &x,int &y)
{
    int t=x;
    x=y;
    y=t;
}

int main()
{
    memset(c,0,sizeof(c));
    for (int i=1;i<=10000;i++)
    c[i]=check(i);
    int i,j;
    while (cin>>i>>j)
    {
        cout<<i<<' '<<j<<' ';
        if (i>j) swap(i,j);
        int max=0;
        for (int k=i;k<=j;k++)
        if (max<c[k]) max=c[k];
        cout<<max<<endl;
    }
    return 0;
}
