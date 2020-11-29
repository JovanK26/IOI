#include <bits/stdc++.h>
/*
   Solution by Jovan Kašćelan
*/
using namespace std;
int n,s;
bool is[801][801];
int tim[801][801];
bool vis[801][801];
struct field
{
    int x,y;
};
vector<field> hives;
field start;
field home;
bool check(int m)
{
     bool visited[801][801];
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             visited[i][j]=0;
         }
     }
     if(m>=tim[start.x][start.y])return 0;
     queue<pair<field,int> > q;
     q.push(make_pair(start,0));
     while(!q.empty())
    {
        auto x=q.front();
        q.pop();
        field cur=x.first;
        if(cur.x==home.x && cur.y==home.y)return 1;
        int d=x.second;
        visited[cur.x][cur.y]=1;
        if(cur.x+1<n && !visited[cur.x+1][cur.y] && is[cur.x+1][cur.y] && m+(d+1)/s<tim[cur.x+1][cur.y])
        {
            cur.x++;
            visited[cur.x][cur.y]=1;
            q.push(make_pair(cur,d+1));
            cur.x--;
        }
        if(cur.x-1>=0 && !visited[cur.x-1][cur.y] && is[cur.x-1][cur.y] && m+(d+1)/s<tim[cur.x-1][cur.y])
        {
            cur.x--;
            visited[cur.x][cur.y]=1;
            q.push(make_pair(cur,d+1));
            cur.x++;
        }
        if(cur.y+1<n && !visited[cur.x][cur.y+1] && is[cur.x][cur.y+1] && m+(d+1)/s<tim[cur.x][cur.y+1])
        {
            cur.y++;
            visited[cur.x][cur.y]=1;
            q.push(make_pair(cur,d+1));
            cur.y--;
        }
        if(cur.y-1>=0 && !visited[cur.x][cur.y-1] && is[cur.x][cur.y-1] && m+(d+1)/s<tim[cur.x][cur.y-1])
        {
            cur.y--;
            visited[cur.x][cur.y]=1;
            q.push(make_pair(cur,d+1));
            cur.y++;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    char c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           cin >> c;
           if(c=='T')
           {
               is[i][j]=0;
           }
           else if(c=='M')
           {
               is[i][j]=1;
               start.x=i;
               start.y=j;
           }
           else if(c=='D')
           {
               is[i][j]=1;
               home.x=i;
               home.y=j;
           }
           else if(c=='H')
           {
               is[i][j]=0;
               field temp;
               temp.x=i;
               temp.y=j;
               hives.push_back(temp);
           }
           else
           {
               is[i][j]=1;
           }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            tim[i][j]=1000000000;
        }
    }
    queue<pair<field,int> > q;
    for(int i=0;i<hives.size();i++)
    {
        q.push(make_pair(hives[i],0));
        vis[hives[i].x][hives[i].y]=1;
    }
    while(!q.empty())
    {
        auto x=q.front();
        q.pop();
        field cur=x.first;
        int d=x.second;
        if(cur.x==home.x && cur.y==home.y)continue;
        vis[cur.x][cur.y]=1;
        tim[cur.x][cur.y]=min(tim[cur.x][cur.y],d);
        if(cur.x+1<n && !vis[cur.x+1][cur.y] && is[cur.x+1][cur.y])
        {
            cur.x++;
            vis[cur.x][cur.y]=1;
            q.push(make_pair(cur,d+1));
            cur.x--;
        }
        if(cur.x-1>=0 && !vis[cur.x-1][cur.y] && is[cur.x-1][cur.y])
        {
            cur.x--;
            vis[cur.x][cur.y]=1;
            q.push(make_pair(cur,d+1));
            cur.x++;
        }
        if(cur.y+1<n && !vis[cur.x][cur.y+1] && is[cur.x][cur.y+1])
        {
            cur.y++;
            vis[cur.x][cur.y]=1;
            q.push(make_pair(cur,d+1));
            cur.y--;
        }
        if(cur.y-1>=0 && !vis[cur.x][cur.y-1] && is[cur.x][cur.y-1])
        {
            cur.y--;
            vis[cur.x][cur.y]=1;
            q.push(make_pair(cur,d+1));
            cur.y++;
        }
    }
    tim[home.x][home.y]=1000000000;
    int l=0;
    int r=1000000;
    int m;
    int rez=-1;
    while(l<r)
    {
        m=(l+r)/2;
        if(check(m))
        {
            l=m+1;
            rez=max(rez,m);
        }
        else
        {
            r=m;
        }
    }
    cout << rez;
    return 0;
}
