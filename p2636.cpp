#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t)
    {
        t --;
        int k;
        cin>>k;
        int sum = 0;
        for (int i = 0;i < k;i ++)
        {
            int a;
            cin>>a;
            sum += a;
        }
        sum -= k - 1;
        cout<<sum<<endl;
    }
}
