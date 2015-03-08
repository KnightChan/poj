#include<cstdio>
#include<iostream>
using namespace std;
int find_min(int x,int y,int z)
{
    int j=1,_min=x;
    if (_min>y){j=2;_min=y;}
    if (_min>z){j=3;_min=z;}
    return j;
}
int i,j,k,d[4],Start,n,t[]={0,23,28,33};
int main()
{
    cin>>d[1]>>d[2]>>d[3]>>Start;
    k=0;
    while (d[1]!=-1)
    {
        k++;
        while ((d[1]!=d[2])||(d[2]!=d[3])||(d[1]<=Start))
        {
            j=find_min(d[1],d[2],d[3]);
            d[j]+=t[j];
        }

        j=(d[1]-Start)%21252;
        if (!j)j=21252;
        printf("Case %d: the next triple peak occurs in %d days.\n",k,j);
        cin>>d[1]>>d[2]>>d[3]>>Start;
    }
    return 0;
}
