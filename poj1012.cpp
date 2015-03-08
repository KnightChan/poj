#include<iostream>
using namespace std;
int a[15],f[29],j,i,in[29];
int ans[]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,13482720};

bool check(int n,int x)
{
    int cout=0,l,now=x,rest=2*n,temp=x;
    now=now%(n<<1);
    if (now==0) now=(n<<1);
    while (cout<n)
    {
        if (f[now]) return 0;
        cout++;
        in[now]=0;
        rest--;
        l=0;
        temp=x;
        temp=temp%rest;
        if (temp==0) temp=rest;
        while (l<temp)
        {
            now++;
            if (now>(n<<1)) now=1;
            if (in[now]) l++;
        }
    }
    return 1;
}

int main()
{
    for (i=1;i<=14;i++)
    {
        memset(f,0,sizeof(f));

        for (j=1;j<=i;j++) f[j]=1;
        for (j=i+1;j<=13489999;j++)
        {
            memset(in,1,sizeof(in));
            if (check(i,j))
            {
                a[i]=j;
                cout << i <<": " << j <<' '<<endl;
                break;
            }
        }
    }
    //for (i=1;i<=14;i++) cout << a[i] <<' ';
    //cout<<endl;
    /*int n;
    cin>>n;
    while (n)
    {
        cout<<ans[n]<<endl;
        cin>>n;
    }*/
    return 0;
}
