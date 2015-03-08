#include<iostream>
using namespace std;
int i,j,n,k,a[7],sum,m,zz=300;
bool f[300000];

bool init(int *a)
{
    int i;
    for (i=1;i<=6;i++)
    if (a[i])return 1;
    return 0;
}
int main()
{
    for (i=1;i<=6;i++) { cin>>a[i];if (a[i]>zz) a[i]=a[i]%zz;}
    k=0;
    while (init(a))
    {
        sum=0;
        k++;
        cout<<"Collection #"<<k<<":"<<endl;
        for (i=1;i<=6;i++) sum+=a[i]*i;
        if (sum%2==1)
        {
            cout<<"Can't be divided."<<endl<<endl;
            for (i=1;i<=6;i++) { cin>>a[i];if (a[i]>zz) a[i]=a[i]%zz;}
            continue;
        }
        memset(f,0,sizeof(f));
        f[0]=1;
        for (i=1;i<=6;i++)
        if (a[i]){
        for (j=0;j<=sum/2;j++)
        for (m=1;m<=a[i];m++)
        if (j>=i*m&&f[j-i*m]) f[j]=1;
        }
        if (f[sum/2]) cout<<"Can be divided."<<endl<<endl;
        else cout<<"Can't be divided."<<endl<<endl;
        for (i=1;i<=6;i++) { cin>>a[i];if (a[i]>zz) a[i]=a[i]%zz;}
    }
}
