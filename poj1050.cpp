#include<cstdio>
#include<string>

int max(int a,int b)
{
    if (a>b) return a;
    return b;
}

int main()
{
    int n,f[101][101],temp,ans=-2147483648;
    scanf("%d",&n);
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    {
        scanf("%d",&temp);
        f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+temp;
    }

    /*for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        printf("%d ",f[i][j]);
        printf("\n");
    }*/

    for (int x1=0;x1<=n;x1++)
    for (int y1=0;y1<=n;y1++)
    for (int x2=x1;x2<=n;x2++)
    for (int y2=y1;y2<=n;y2++)
    ans=max(ans,f[x2][y2]+f[x1][y1]-f[x1][y2]-f[x2][y1]);
    printf("%d\n",ans);
    return 0;
}
