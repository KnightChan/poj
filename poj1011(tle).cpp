#include<algorithm>
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int a[66],i,j,n,_min,_max,f[66],k[66][66];
void swap(int &x,int &y)
{
    int t=x;
    x=y;
    y=t;
}

bool check(int x,int m,int l)
{
    int i;
    if ((m-x<a[n])&&(m>x))return 0;
    if (x==m)
    {
        x=0;
        l--;
    }
    if (l==1)return 1;
    for (i=1;i<=n;i++)
    if ((x+a[i]<=m)&&(f[i]==false))
    {
        f[i]=true;
        if (check(x+a[i],m,l))return 1;
        f[i]=false;
    }
    return 0;
}

void q_sort(int l,int r)
{
    int mid=a[(l+r)>>1],i=l,j=r;
    while (i<j)
    {
        while (a[i]>mid)i++;
        while (a[j]<mid)j--;
        if (i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if (l<j)q_sort(l,j);
    if (i<r)q_sort(i,r);
}

int main()
{
    scanf("%d",&n);
    bool flag;
    while (n>0)
    {
        _max=0;
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            _max+=a[i];
        }
        q_sort(1,n);
        _min=a[1];
        flag=1;
        for (i=_min;i<=_max/2;i++)
        if ((_max%i)==0)
        {

            memset(f,0,sizeof(f));
            memset(k,0,sizeof(k));
            f[0]=1;
            if (check(0,i,_max/i))
            {
                flag=0;
                printf("%d\n",i);
                break;
            }
        }
        if (flag) printf("%d\n",_max);
        scanf("%d",&n);
    }
    return 0;
}
