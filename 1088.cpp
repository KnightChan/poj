#include<cstdio>
#include<string>
int f[101][101],i,j,k,n,m,a[101][101],_max,ff[101][101];
int dfs(int x,int y)
{
    int temp,mm=1;
    if (ff[x][y]) return f[x][y];
    if (x-1>0&&a[x][y]>a[x-1][y])
    {
        temp=dfs(x-1,y);
        ff[x-1][y]=1;
        f[x-1][y]=temp;
        if (temp+1>mm) mm=temp+1;
    }
    if (y-1>0&&a[x][y]>a[x][y-1])
    {
        temp=dfs(x,y-1);
        ff[x][y-1]=1;
        f[x][y-1]=temp;
        if (temp+1>mm) mm=temp+1;
    }
    if (x+1<=n&&a[x][y]>a[x+1][y])
    {
        temp=dfs(x+1,y);
        ff[x+1][y]=1;
        f[x+1][y]=temp;
        if (temp+1>mm) mm=temp+1;
    }
    if (y+1<=m&&a[x][y]>a[x][y+1])
    {
        temp=dfs(x,y+1);
        ff[x][y+1]=1;
        f[x][y+1]=temp;
        if (temp+1>mm) mm=temp+1;
    }
    return mm;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    scanf("%d",&a[i][j]);
    memset(f,0,sizeof(f));
    memset(ff,0,sizeof(ff));
    _max=0;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if (ff[i][j]==0)
    {
        f[i][j]=dfs(i,j);
        ff[i][j]=1;
        if (_max<f[i][j]) _max=f[i][j];
    }
    printf("%d\n",_max);
    return 0;
}
