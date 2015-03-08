#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t)
    {
        t --;
        int h,m;
        scanf("%d:%d", &h, &m);
        int ans = 0;
        if (!m)
        {
            if (h > 12) ans = h - 12;
            else ans = h + 12;
        }
        cout<<ans<<endl;
    }
    return 0;
}
