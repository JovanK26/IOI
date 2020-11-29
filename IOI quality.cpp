#include "grader.h"
int n,m,r,c;
int pref1[3005][3005];
int pref2[3005][3005];
int a[3005][3005];
bool check(int val)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            pref1[i][j]=pref1[i-1][j]+pref1[i][j-1]-pref1[i-1][j-1]+(a[i][j]>val);
            pref2[i][j]=pref2[i-1][j]+pref2[i][j-1]-pref2[i-1][j-1]+(a[i][j]<val);
        }
    }
    for(int i=1;i+r-1<=n;i++)
    {
        for(int j=1;j+c-1<=m;j++)
        {
            int sumh=pref1[i+r-1][j+c-1]-pref1[i-1][j+c-1]-pref1[i+r-1][j-1]+pref1[i-1][j-1];
            int suml=pref2[i+r-1][j+c-1]-pref2[i-1][j+c-1]-pref2[i+r-1][j-1]+pref2[i-1][j-1];
            if(suml>=sumh)return 1;
        }
    }
    return 0;
}
int rectangle( int _n , int _m , int _r , int _c , int M[3001][3001] ){

	n=_n;
	m=_m;
	r=_r;
	c=_c;
	for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=M[i-1][j-1];
        }
    }
    int hi=n*m;
    int lo=1;
    int med;
    while(lo<hi)
    {
        med=(lo+hi)/2;
        if(check(med))
        {
            hi=med;
        }
        else
        {
            lo=med+1;
        }
    }
    return hi;
}
