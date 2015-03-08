//poj1716
//典型的差分约束系统。
//算法思路蒋岩炎已经在上课的时候说过，就是利用最短路的求法。
//此题我是用的spfa的做法来求的最短路，不过当时交的时候还是挺危险的，900多MS险过。- -!~

//下面请看代码：

#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

struct AAA
{
    int v,len;
};

const int MAX=2147483647;
vector<AAA> p[100001];
int q[2100000],d[100001],_max=0,f[100001],_min=MAX;

void Swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}

void SPFA(int v0)//spfa算法的具体代码。
{
    int l=0,r=1,i;
    vector<AAA> temp;
    for (i=_min;i<=_max+1;i++) d[i]=MAX;
    q[1]=v0;d[v0]=0;f[v0]=1;
    while (l<r)
    {
        l++;
        f[q[l]]=0;
        temp=p[q[l]];
        for (i=0;i<temp.size();i++)
        if (d[q[l]]+temp[i].len<d[temp[i].v])
        {
            d[temp[i].v]=d[q[l]]+temp[i].len;
            if (!f[temp[i].v])
            {
                r++;
                q[r]=temp[i].v;
                f[temp[i].v]=1;
            }
        }
    }
}

int main()
{
    int n,b,a;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)//读入数据构图。
    {
        AAA dd;
        scanf("%d%d",&a,&b);
        if (a>b) Swap(a,b);
        dd.len=-2;
        dd.v=b+1;
        p[a].push_back(dd);
        if (b>_max) _max=b;
        if (a<_min) _min=a;
    }
    for (int i=_min;i<=_max;i++)//构图。
    {
        AAA dd;
        dd.len=1;
        dd.v=i;
        p[i+1].push_back(dd);
        dd.len=0;
        dd.v=i+1;
        p[i].push_back(dd);
    }
    memset(d,0,sizeof(d));
    memset(f,0,sizeof(f));
    SPFA(_min);//做spfa
    printf("%d\n",-d[_max+1]+d[_min]);//输出结果。
    return 0;
}
