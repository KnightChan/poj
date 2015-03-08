#include<iostream>
using namespace std;

int nine_to_10(int n)
{
    int ans = 0;
    int nine = 1;

    while (n)
    {
        ans += nine * (n % 10 > 4?n % 10 - 1:n % 10);
        nine *= 9;
        n /= 10;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    while (n)
    {
        cout<<n<<": "<<nine_to_10(n)<<endl;
        cin>>n;
    }
    return 0;
}
