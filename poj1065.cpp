#include<cstdio>
#include<string>
#include<algorithm>

struct Node
{
    int l,w;
}a[5001];

bool f[5001];
bool cmp(Node a,Node b)
{
    if (a.l<b.l) return 1;
    if (a.l==b.l&&a.w<b.w) return 1;
    return 0;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    for (int c=1;c<=t;c++)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i].l,&a[i].w);
        std::sort(a+1,a+1+n,cmp);

        /*for (int i=1;i<=n;i++)
        printf("%d %d,",a[i].l,a[i].w);
        printf("\n");
*/
        int ans=0,cou=0;
        memset(f,0,sizeof(f));
        while (cou<n)
        {
            ans++;
            int pl=0,pw=0;
            for (int i=1;i<=n;i++)
            if (a[i].l>=pl&&a[i].w>=pw&&f[i]==0)
            {
                f[i]=1;
                pl=a[i].l;
                pw=a[i].w;
                cou++;
            }
        }
        printf("%d\n",ans);
    }
}
