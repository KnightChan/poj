#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1[]={"","pop", "no", "zip", "zotz", "tzec", "xul","yoxkin"
    , "mol", "chen", "yax", "zac", "ceh", "mac", "kankin",
    "muan", "pax", "koyab", "cumhu","uayet"},
    s2[]={"","imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix",
    "mem","cib","caban","eznab","canac","ahau"};
    int i,n,y1,y2,d1,d2,m1,m2;
    char ch;
    string s;
    cin>>n;
    cout << n << endl;
    while (n>0)
    {
        --n;
        cin>>ch;
        d1=0;
        while (ch!='.') {d1=d1*10+ch-48;cin>>ch;}
        d1++;
        cin>>s>>y1;
        for (i=1;i<=19;i++) if (s==s1[i]) m1=i;
        d1+=(m1-1)*20+y1*365;
        y2=d1/260;
        d2=d1%13;
        if (d2==0)d2=13;
        d1=d1%260;
        if (d1==0) {cout<<d2<<' '<<s2[20]<<' '<<y2-1<<endl;continue;}
        m2=d1%20;
        if (m2==0)m2=20;
        cout<<d2<<' '<<s2[m2]<<' '<<y2<<endl;
    }
    return 0;
}
