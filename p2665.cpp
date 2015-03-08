#include<iostream>
using namespace std;

int main()
{
    int len, l, r, t;
    cin>>len>>t;
    while (len > 0 && t > 0)
    {
        while (t)
        {
            t --;
            cin>>l>>r;
            len -= r - l + 1;
        }
        cout<<len + 1<<endl;
        cin>>len>>t;
    }
    return 0;
}
