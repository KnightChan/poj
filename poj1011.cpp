#include<algorithm>
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int a[66],i,j,k,n,_min,_max,f[66];
void swap(int &x,int &y)
{
    int t=x;
    x=y;
    y=t;
}

bool check(int x,int m,int l)
{
    int i;
    if (x==m)
    {
        x=0;
        l--;
    }
    if (l==0)return true;
    for (i=1;i<=n;i++)
    if ((f[i]==false)&&(x+a[i]<=m))
    {
        f[i]=true;
        if (check(x+a[i],m,l))return 1;
        else f[i]=false;
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

        cout<<_min<<' '<<_max<<endl;

        for (i=_min;i<=_max;i++)
        if ((_max%i)==0)
        {

            memset(f,0,sizeof(f));
            if (check(0,i,_max/i))
            {
                printf("%d\n",i);
                break;
            }
        }
        scanf("%d",&n);
    }
    return 0;
}
