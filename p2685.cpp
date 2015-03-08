#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int num1[4];
int num2[4];
string numstr1, numstr2;

void clear_mcxi()
{
    memset(num1, 0, sizeof(num1));
    memset(num2, 0, sizeof(num2));
}

int in_mcxi(char a)
{
    if (a == 'm') return 0;
    if (a == 'c') return 1;
    if (a == 'x') return 2;
    if (a == 'i') return 3;
    return -1;
}

void get_num(string numstr, int *num)
{
    int len = numstr.length();
    int tmp = 0;
    for (int i = 0;i < len;i ++)
    {
        int in = in_mcxi(numstr[i]);
        if (in >= 0)
        {
            num[in] = tmp==0?1:tmp;
            tmp = 0;
        }else
        tmp = tmp * 10 + numstr[i] - '0';
    }
}

void add_num(int *num1, int *num2)
{
    for (int i = 0;i < 4;i ++)
        num1[i] += num2[i];
    for (int i = 3;i > 0;i --)
    {
        num1[i - 1] += num1[i] / 10;
        num1[i] = num1[i] % 10;
    }
}

void print_num(int *num)
{
    for (int i = 0;i < 4;i ++)
        cout<<num[i];
    cout<<endl;
}

int main()
{
    int t;
    string mcxi = "mcxi";
    cin>>t;
    while (t>0)
    {
        t --;
        cin>>numstr1;
        cin>>numstr2;
        clear_mcxi();
        get_num(numstr1, num1);
        get_num(numstr2, num2);
        //print_num(num1);
        //print_num(num2);
        add_num(num1, num2);
        for (int i = 0;i < 4;i ++)
        if (num1[i] > 0)
        {
            if (num1[i] > 1)
                cout<<num1[i];
            cout<<mcxi[i];
        }
        cout<<endl;
    }
    return 0;
}
