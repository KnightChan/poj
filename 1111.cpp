#include<iostream>
using namespace std;
int a[22][22],n,m,xx,yy,f[22][22],i,j,sum;

void dfs(int x,int y)
{
    //cout<<x<<' '<<y<<' '<<sum<<endl;
    if ((x<1)||(x>n)||(y<1)||(y>m)||(a[x][y])||(f[x][y]))
    return;
    f[x][y]=1;
    sum=sum+a[x][y-1]+a[x][y+1]+a[x+1][y]+a[x-1][y];
    dfs(x,y-1);
    dfs(x,y+1);
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x+1,y-1);
    dfs(x+1,y+1);
    dfs(x-1,y+1);
    dfs(x-1,y-1);
}

int main()
{
    char ch;
    cin>>n>>m>>xx>>yy;
    while (n+m+xx+yy)
    {
        memset(f,0,sizeof(f));
        sum=0;
        for (i=1;i<=n;i++) { a[i][0]=1;a[i][m+1]=1;}
        for (i=1;i<=m;i++) { a[0][i]=1;a[n+1][i]=1;}
        for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        {
            cin>>ch;
            a[i][j]=1;
            if (ch=='X') a[i][j]=0;
        }
        dfs(xx,yy);
        cout<<sum<<endl;
        cin>>n>>m>>xx>>yy;
    }
}
