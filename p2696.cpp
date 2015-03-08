#include<iostream>
#include<cstdio>
using namespace std;

int ff[1001];
int a,b,c,d,e,f,g,h,i;
const int inf = 1001;

void clear_ff_to_inf()
{
    for (int i = 0;i < 1001;i ++)
        ff[i] = inf;
}

int get_fi(int i)
{
    if (ff[i] != inf) return ff[i];
    if (i & 1)
    {
        ff[i] = d * get_fi(i - 1) +
                e * get_fi(i - 2) -
                f * get_fi(i - 3);
        ff[i] %= g;
        if (ff[i] < 0) ff[i] += g;
    }
    else
    {
        ff[i] = f * get_fi(i - 1) -
                d * get_fi(i - 2) +
                e * get_fi(i - 3);
        ff[i] %= h;
        if (ff[i] < 0) ff[i] += h;
    }
    return ff[i];
}

int main()
{
    int t = 0;
    cin>>t;
    while (t)
    {
        t --;
        cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
        clear_ff_to_inf();
        ff[0] = a;
        ff[1] = b;
        ff[2] = c;
        int ans = get_fi(i);
        cout<<ans<<endl;
    }
    return 0;
}
