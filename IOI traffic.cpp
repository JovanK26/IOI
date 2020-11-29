#include <bits/stdc++.h>
#include "grader.h"
using namespace std;
int n;
int sum=0;
int mini=2000000000;
int ind;
vector<int> v[1000001];
int f[1000001];
int a[1000001];
int cur=0;
void calc(int start,int prev)
{
    f[start]=a[start];
    int maks=0;
    for(int j : v[start])
    {
        if(j==prev)continue;
        calc(j,start);
        f[start]+=f[j];
        maks=max(maks,f[j]);
    }
    maks=max(maks,sum-f[start]);
    if(maks<=mini)
    {
        mini=maks;
        ind=start;
    }
}
int LocateCentre(int N, int pp[], int S[], int D[])
{
    n=N;
    for(int i=0;i<n;i++)
    {
        sum+=pp[i];
        a[i]=pp[i];
    }
    for(int i=0;i<n-1;i++)
    {
        v[S[i]].push_back(D[i]);
        v[D[i]].push_back(S[i]);
    }
    calc(0,-1);
    return ind;
}
/*int main()
{
    int N;
    cin >> N;
    int pp[N];
    int S[N-1];
    int D[N-1];
    for(int i=0;i<N;i++)
    {
        cin >> pp[i];
    }
    for(int i=0;i<N-1;i++)
    {
        cin >> S[i]>>D[i];
    }
    cout<<LocateCentre(N,pp,S,D);
    return 0;
}
*/
