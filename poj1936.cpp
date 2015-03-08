//此题比较简单，就是一个双指针，复杂度为O(n+m)，n和m分别为字符串s1，s2的长度。
//由于过于简单，我就不多说了，请直接看代码吧，

#include<iostream>
#include<string>
using namespace std;
string s1,s2;
bool check()
{
    int l1=s1.length(),l2=s2.length(),i=0,j=0;
    while (i<l1&&j<l2)
    {
        if (s1[i]==s2[j])
        {
            i++;
            j++;
            continue;
        }
        j++;
    }
    if (i==l1) return 1;
    return 0;
}

int main()
{
    while (cin>>s1>>s2)
    if (check()) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
