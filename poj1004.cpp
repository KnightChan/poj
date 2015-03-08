#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float a,o;
    int i;
    for (i=1;i<13;++i)
    {
        cin>>a;
        o+=a;
    }
    cout<<'$'<<fixed<<setprecision(2)<<o/12;
    return 0;
}
