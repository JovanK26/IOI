#include <bits/stdc++.h>
#include "sorting.h"
using namespace std;
int sz,l,r,rez,m;
int S1[500005],A[500005];
vector < pair<int,int > > v;
int findSwapPairs(int N, int S[], int M, int X[], int Y[], int P[], int Q[])
{
    l=0;
    r=M;
    rez=-1;
    while(l<=r)
    {
        m=(l+r)/2;
        for(int i=0;i<N;i++)
        {
            S1[i]=S[i];
        }
        for(int i=0;i<m;i++)
        {
            swap(S1[X[i]],S1[Y[i]]);
        }
        for(int i=0;i<N;i++)
        {
            A[S1[i]]=i;
        }
        v.clear();
        for(int i=0;i<N;i++)
        {
            if(S1[i]==i)continue;
            v.push_back(make_pair(i,S1[i]));
            swap(S1[i],S1[A[i]]);
            swap(A[i],A[S1[A[i]]]);
        }
        sz=v.size();
        if(sz<=m)
        {
            for(int i=0;i<N;i++)
            {
                S1[i]=S[i];
                A[S1[i]]=i;
            }
            for(int i=0;i<M;i++)
            {
                swap(A[S1[X[i]]],A[S1[Y[i]]]);
                swap(S1[X[i]],S1[Y[i]]);
                if(i<sz)
                {
                    P[i]=A[v[i].first];
                    Q[i]=A[v[i].second];
                    swap(A[v[i].first],A[v[i].second]);
                    swap(S1[A[v[i].first]],S1[A[v[i].second]]);
                }
                else
                {
                    P[i]=0;
                    Q[i]=0;
                }
            }
            r=m-1;
            rez=m;
        }
        else
        {
            l=m+1;
        }
    }
    return rez;
}
