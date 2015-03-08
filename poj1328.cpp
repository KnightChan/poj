//poj1328
//此题的解法为贪心，算法思路老师已经讲过，我就不多说了。

//不过当时写这个题的时候还是出了狠多错误，和老师说的一样，
//测试数据应该是有很恶心的，然后自己针对那些恶心数据改动了一下，就过掉了，还是比较幸运的。

//下面请看代码：
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>

struct Node
{
    double l,r;
}a[1001];//记录每个岛屿的信息。

bool cmp(Node a,Node b)
{
    if (a.r<b.r) return 1;
    return 0;
}

int main()
{
    int n,d,k=0,f[1001];
    scanf("%d%d",&n,&d);
    while (n)
    {
        k++;
        bool flag=0;
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if (abs(y)>d)
            {
                flag=1;
            }
            a[i].l=x-sqrt((double)(d*d-y*y));
            a[i].r=x+sqrt((double)(d*d-y*y));
        }
        if (flag)
        {
            printf("Case %d: %d\n",k,-1);
            scanf("%d%d",&n,&d);
            continue;
        }
        std::sort(a+1,a+n+1,cmp);//按照右边界排序，
        int ans=0;
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)//按顺序处理每个岛屿。
        if (!f[i])//如果第i个岛屿还没有被覆盖过，就加一个雷达覆盖。
        {
            ans++;
            f[i]=1;
            for (int j=i+1;j<=n;j++)//跟新新加的这个雷达能覆盖的岛屿，并将它们标记为覆盖过。
            if (a[i].r>=a[j].l) f[j]=1;
        }
        printf("Case %d: %d\n",k,ans);//输出需要的雷达数。
        scanf("%d%d",&n,&d);//读入下一组数据。
    }
    return 0;
}
