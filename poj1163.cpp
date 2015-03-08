#include<iostream>
using namespace std;
int main()
{
    int n,j,i,a[101][101],f[101][101];
    cin>>n;
    for (i=1;i<=n;++i)
    for (j=1;j<=i;++j)
    cin>>a[i][j];
    f[1][1]=a[1][1];
    for (i=2;i<=n;++i)
    for (j=1;j<=i;++j)
    {
        if (f[i-1][j]>f[i-1][j-1])
        f[i][j]=f[i-1][j]+a[i][j];
        else f[i][j]=f[i-1][j-1]+a[i][j];
    }
    int o=0;
    for (i=1;i<=n;++i)
    if (f[n][i]>o) o=f[n][i];
    cout<<o<<endl;
    return 0;
}
