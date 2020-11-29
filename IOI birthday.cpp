#include <bits/stdc++.h>

using namespace std;
int n;
int p[1000001];
int a[1000001];
int b[1000001];
int solve()
{
    int br=0;
    int maks=0;
    int maks1=0;
    int maks2=0;
    for(int i=0;i<n;i++)
    {
        if(!b[i])br++;
        else
        {
            br=0;
        }
        maks1=max(maks1,br);
    }
    for(int i=0;i<n;i++)
    {
        if(b[i])break;
        maks2++;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(b[i])break;
        maks2++;
    }
    maks=max(maks1,maks2);
    return (n-maks)/2;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> p[i];
        a[p[i]-1]=i;
    }
    for(int i=0;i<n;i++)
    {
        b[(a[i]-i+n)%n]++;
    }
    int rez=solve();
    for(int i=0;i<n;i++)
    {
        b[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        b[(a[n-i-1]-i+n)%n]++;
    }
    rez=min(rez,solve());
    cout << rez;
    return 0;
}
