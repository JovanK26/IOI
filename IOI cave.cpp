#include "cave.h"
#include <bits/stdc++.h>
using namespace std;

int n,cur;
int s[5005];
int d[5005];
bool vis[5005];
bool check(int x,int y)
{
    for(int i=x;i<=y;i++)
    {
        if(vis[i])continue;
        s[i]^=1;
    }
    int q=tryCombination(s);
    for(int i=x;i<=y;i++)
    {
        if(vis[i])continue;
        s[i]^=1;
    }
    if(q>cur || q==-1)return 1;
    return 0;
}
void exploreCave(int N)
{
    n=N;
    for(int i=0;i<n;i++)
    {
        cur=i;
        int q=tryCombination(s);
        if(q>cur || q==-1)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[j])continue;
                s[j]^=1;
            }
        }
        int l=0;
        int r=n-1;
        int m;
        while(l<r)
        {
           m=(l+r)/2;
           if(check(l,m))
           {
               r=m;
           }
           else
           {
               l=m+1;
           }
        }
        vis[r]=1;
        d[r]=i;
        s[r]^=1;
    }
    answer(s,d) ;
}
