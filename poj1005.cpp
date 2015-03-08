#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n,i,j=0,k;
    float x,y,a[1001],d;
    cin>>n;
    for (i=1;i<=n;++i)
    {
        cin>>x>>y;
        d=sqrt(pow(x,2)+y*y);
        if (a[j]>d)
        {
            k=j;
            while (a[k]>d) --k;
            cout<<"Property "<<i<<": This property will begin eroding in year "<<k+1<<'.'<<endl;
            continue;
        }
        while (a[j]<d)
        {
            ++j;
            a[j]=sqrt((50*j*2)/3.1415926);
        }
        cout<<"Property "<<i<<": This property will begin eroding in year "<<j<<'.'<<endl;
    }
    cout<<"END OF OUTPUT."<<endl;
    return 0;
}
