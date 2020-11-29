#include "shoes.h"
#include<bits/stdc++.h>
using namespace std;
int bit[200001];
void update(int x,int n,int val)
{
    x++;
    while(x<=n)
    {
        bit[x]+=val;
        x+=(x&(-x));
    }
}
int query(int x)
{
    int rez=0;
    x++;
    while(x>0)
    {
        rez+=bit[x];
        x-=(x&(-x));
    }
    return rez;
}
map<int,vector<int> >mp;
long long count_swaps(vector<int> s)
{
    long long rez=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        update(i,n,1);
    }
    for(int i=n-1;i>=0;i--)
    {
        mp[s[i]].push_back(i);
    }
    for(int i=0;i<n;i++)
    {
        if(query(i)-query(i-1)!=1)continue;
        int j=mp[-s[i]].back();
        mp[s[i]].pop_back();
        mp[-s[i]].pop_back();
        update(i,n,-1);
        update(j,n,-1);
        rez+=query(j)-query(i)+(s[i]>0);
    }
    return rez;
}
/*int main()
{
    int n;
    cin >> n;
    vector<int> s(2*n);
    for(int i=0;i<2*n;i++)
    {
        cin >> s[i];
    }
    cout << count_swaps(s);
    return 0;
}
*/
