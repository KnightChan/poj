#include<iostream>
using namespace std;
int a[7],i,j,k,n,f[2570],sum,in[7];
bool check(int now,int n,int su)
{
    int i;
    if (now>su) return 0;
    if (now==su) return 1;
    for (i=1;i<=n;i++)
    if (in[i]==0)
    {
        in[i]=1;
        if (check(now+a[i],n,su)) return 1;
        in[i]=0;
    }
    return 0;
}

int change(int x1,int x2,int x3,int x4,int x5,int x6)
{
    return(x1*32+x2*16+x3*8+x4*4+x5*2+x6);
}

bool init(int x1,int x2,int x3,int x4,int x5,int x6)
{
    if (x1) return 1;
    if (x2) return 1;
    if (x3) return 1;
    if (x4) return 1;
    if (x5) return 1;
    if (x6) return 1;
    return 0;
}

int main()
{
    int i1,i2,i3,i4,i5,i6;
    memset(f,0,sizeof(f));
    for (i1=0;i1<=1;i1++)
    for (i2=0;i2<=1;i2++)
    for (i3=0;i3<=1;i3++)
    for (i4=0;i4<=1;i4++)
    for (i5=0;i5<=1;i5++)
    for (i6=0;i6<=1;i6++)
    {
        i=0;
        memset(in,0,sizeof(in));
        sum=0;
        if (i1!=0) { i++;a[i]=i1;sum+=a[i];}
        if (i2!=0) { i++;a[i]=i2*2;sum+=a[i];}
        if (i3!=0) { i++;a[i]=3*i3;sum+=a[i];}
        if (i4!=0) { i++;a[i]=4*i4;sum+=a[i];}
        if (i5!=0) { i++;a[i]=5*i5;sum+=a[i];}
        if (i6!=0) { i++;a[i]=6*i6;sum+=a[i];}
        if (sum%2==1) continue;
        if (check(0,i,sum/2)) f[change(i1,i2,i3,i4,i5,i6)]=1;
    }
    for (i1=0;i1<=1;i1++)
    for (i2=0;i2<=1;i2++)
    for (i3=0;i3<=1;i3++)
    for (i4=0;i4<=1;i4++)
    for (i5=0;i5<=1;i5++)
    for (i6=0;i6<=1;i6++)
        cout<<i1<<i2<<i3<<i4<<i5<<i6<<endl<<f[change(i1,i2,i3,i4,i5,i6)]<<endl;
    cin>>i1>>i2>>i3>>i4>>i5>>i6;
    k=0;
    while (init(i1,i2,i3,i4,i5,i6))
    {
        k++;
        cout<<"Collection #"<<k<<":"<<endl;
        i1=i1%2;
        i2=i2%2;
        i3=i3%2;
        i4=i4%2;
        i5=i5%2;
        i6=i6%2;
        //cout<<i1<<i2<<i3<<i4<<i5<<i6<<endl;
        if (f[change(i1,i2,i3,i4,i5,i6)]) cout<<"Can be divided.";
        else cout<<"Can't be divided.";
        cout<<endl<<endl;
        cin>>i1>>i2>>i3>>i4>>i5>>i6;
    }
    return 0;
}
