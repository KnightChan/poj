#include<iostream>
using namespace std;

int main()
{
    int x,ans=1,y=1;
    while (cin>>x)
    {
        ans=1;y=1;
        while (1)
        {
        if (y%x==0)
        {
            cout<<ans<<endl;
            break;
        }
        y=y*10+1;
        y=y%x;
        ans++;
        }
    }
    return 0;
}
