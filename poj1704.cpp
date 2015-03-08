#include<cstdio>
#include<algorithm>

int a[1002];

bool cmp(int a,int b)
{
    if (a>b) return 1;
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
        scanf("%d",&a[i]);
        std::sort(a+1,a+n+1,cmp);
        n++;
        a[n]=0;

       /* for (int i=1;i<=n;i++)
        printf("%d ",a[i]);
        printf("\n");
*/
        int ans=0;
        for (int i=1;i<=n/2;i++)
        ans^=a[i*2-1]-a[i*2]-1;
        if (!ans) printf("Bob will win\n");
        else printf("Georgia will win\n");
    }
    return 0;
}
