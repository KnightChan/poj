#include<iostream>
#include<string>
using namespace std;
string light,heavy,s1,s2,s3;
int i,j,k,n,f[100];
int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
    {
        memset(f,0,sizeof(f));
        k=0;
        light="";
        heavy="";
        while (k<3)
        {
            k++;
            cin>>s1>>s2>>s3;
            if (s3[0]=='e')
            {
                for (j=0;j<s1.length();j++)
                f[s1[j]]=1;
                for (j=0;j<s2.length();j++)
                f[s2[j]]=1;
            }
            if (s3[0]=='u')
            {
                light+=s2;
                heavy+=s1;
            }
            if (s3[0]=='d')
            {
                light+=s1;
                heavy+=s2;
            }
        }
    //cout<<light<<endl;
    //cout<<heavy<<endl;
    for (j=0;j<light.length();j++)
    if (f[light[j]]==0)
    cout<<light[j]<<" is the counterfeit coin and it is light."<<endl;
    for (j=0;j<heavy.length();j++)
    if (f[heavy[j]]==0)
    cout<<heavy[j]<<" is the counterfeit coin and it is heavy."<<endl;
    }
    return 0;
}
