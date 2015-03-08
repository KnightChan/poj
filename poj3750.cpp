#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

string s[65];
int w=0,c=0,f[65],n,o;

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    cin>>s[i];
    memset(f,0,sizeof(f));
    char st[65];
    scanf("%s",st);
    int l=strlen(st),i=0;
    while (st[i]!=',')
    {
        w=w*10+st[i]-48;
        i++;
    }
    i++;
    while (i<l)
    {
        c=c*10+st[i]-48;
        i++;
    }
    //cin>>w>>c;
    o=n;
    while (o>0)
    {
        int j=0;
        while (j<c)
        {
            if (f[w]==0) j++;
            if (j==c) break;
            w++;
            w%=n;
            if (w==0) w+=n;
        }
        f[w]=1;
        o--;
        cout<<s[w]<<endl;
    }
    return 0;
}
