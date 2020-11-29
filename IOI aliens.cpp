#include <bits/stdc++.h>

using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,x,y;
bool check(int x,int y)
{
    if(x<=0 || y<=0 || x>n || y>n)return 0;
    cout << "examine "<<x<<' '<<y<<endl;
    string rep;
    cin >> rep;
    return (rep=="true");
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x >> y;
    int rim[4];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<30;j++)
        {
            if(!check(x+(1ll << j)*dx[i],y+(1ll << j)*dy[i]))
            {
                int l=0;
                if(j)l=1ll << (j-1);
                int r=1ll << j;
                int m;
                while(l<r)
                {
                    m=(l+r)/2;
                    if(check(x+m*dx[i],y+m*dy[i]))l=m+1;
                    else
                    {
                        r=m;
                    }
                }
                rim[i]=max(0,l-1);
                break;
            }
        }
    }
    x=x+(rim[0]-rim[2])/2;
    y=y+(rim[1]-rim[3])/2;
    int m=(rim[0]+rim[2]+1);
    int ind1,ind2;
    if(check(x+2*m,y) && check(x-2*m,y))
    {
        ind1=2;
        if(check(x,y+2*m) && check(x,y-2*m))ind2=2;
        else if(check(x,y+2*m) && !check(x,y-2*m))ind2=0;
        else
        {
            ind2=4;
        }
    }
    if(check(x,y+2*m) && check(x,y-2*m))
    {
        ind2=2;
        if(check(x+2*m,y) && check(x-2*m,y))ind1=2;
        else if(check(x+2*m,y) && !check(x-2*m,y))ind1=0;
        else
        {
            ind1=4;
        }
    }
    if(check(x+2*m,y) && !check(x-2*m,y) && check(x,y+2*m) && !check(x,y-2*m))
    {
        if(check(x-m,y-m))
        {
            ind1=1;
            ind2=1;
        }
        else
        {
            ind1=0;
            ind2=0;
        }
    }
    if(check(x+2*m,y) && !check(x-2*m,y) && !check(x,y+2*m) && check(x,y-2*m))
    {
        if(check(x-m,y+m))
        {
            ind1=1;
            ind2=3;
        }
        else
        {
            ind1=0;
            ind2=4;
        }
    }
    if(!check(x+2*m,y) && check(x-2*m,y) && check(x,y+2*m) && !check(x,y-2*m))
    {
        if(check(x+m,y-m))
        {
            ind1=3;
            ind2=1;
        }
        else
        {
            ind1=4;
            ind2=0;
        }
    }
    if(!check(x+2*m,y) && check(x-2*m,y) && !check(x,y+2*m) && check(x,y-2*m))
    {
        if(check(x+m,y+m))
        {
            ind1=3;
            ind2=3;
        }
        else
        {
            ind1=4;
            ind2=4;
        }
    }
    cout << "solution " <<x+m*(2-ind1) <<' '<<y+m*(2-ind2)<<endl;
    return 0;
}
