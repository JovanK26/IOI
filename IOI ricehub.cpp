#include <bits/stdc++.h>
#include "ricehub.h"
using namespace std;
long long r,l;
long long b;
long long x[100001];
bool check(long long k)
{
    long long rez=0;
    long long m=(k+1)/2;
    for(long long i=1;i<=k;i++)
    {
        rez+=abs(x[m]-x[i]);
    }
    if(rez<=b)return 1;
    m++;
    for(long long i=2;i+k-1<=r;i++,m++)
    {
        if(k&1)rez+=(x[m]-x[m-1]);
        rez-=(x[m]-x[i-1]);
        rez+=(x[i+k-1]-x[m]);
        if(rez<=b)return 1;
    }
    return 0;
}
int besthub(int R, int L, int* X, long long B){

    r=R;
    l=L;
    for(long long i=0;i<r;i++)
    {
        x[i+1]=X[i];
    }
    b=B;
    long long i=0;
    long long j=r;
    while(i<=j)
    {
        long long m=(i+j)/2;
        if(check(m))
        {
            i=m+1;
        }
        else
        {
            j=m-1;
        }
    }
    return i-1;

}
