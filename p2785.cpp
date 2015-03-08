#include<iostream>
#include<algorithm>
using namespace std;

const int M = 4001;
int n, a[M], b[M], c[M], d[M];
int sum_ab[M * M], sum_cd[M * M];

int find_l(int x, int l, int r, int *f)
{
    int mid = (l + r) / 2;
    if (l == r)
    {
        if (x == f[l])
            return l;
        else return n * n;
    }
    if (x <= f[mid])
    {
        return find_l(x, l, mid, f);
    }else
    {
        return find_l(x, mid + 1, r, f);
    }
}

int count_x(int x, int *f)
{
    static int last_r = n* n - 1;
    int l = find_l(x, 0, last_r, f);
    last_r = l;
    //cout<<"find_l x="<<x<<" "<<l<<endl;
    int count = 0;
    while (l < n * n && x == f[l])
    {
        l ++;
        count ++;
    }
    return count;
}

int main()
{
    cin>>n;
    for (int i = 0;i < n;i ++)
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    int k = 0;
    for (int i = 0;i < n;i ++)
    for (int j = 0;j < n;j ++)
    {
        sum_ab[k] = a[i] + b[j];
        sum_cd[k ++] = c[i] + d[j];
    }
    /*
    for (int i = 0;i < n * n;i ++)
    {
        cout<<sum_ab[i]<<" ";
    }
    cout<<endl;
    for (int i = 0;i < n * n;i ++)
    {
        cout<<sum_cd[i]<<" ";
    }
    cout<<endl;
    */

    sort(sum_ab, sum_ab + n * n);
    sort(sum_cd, sum_cd + n * n);

    /*
    for (int i = 0;i < n * n;i ++)
    {
        cout<<sum_ab[i]<<" ";
    }
    cout<<endl;
    for (int i = 0;i < n * n;i ++)
    {
        cout<<sum_cd[i]<<" ";
    }
    cout<<endl;
    */

    int ans = 0;
    for (int i = 0;i < n * n;i ++)
    {
        int count = count_x(-sum_ab[i], sum_cd);
        //cout<<"count x="<<-sum_ab[i]<<" "<<count<<endl;
        ans += count;
    }

    cout<<ans<<endl;
    return 0;
}
