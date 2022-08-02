#include<bits/stdc++.h>
using namespace std;
struct info{
    int x,y,d;
};

vector< int > v[1000010];
int main()
{
    int n,m,k,ans=0,x,y,d=1;
    cin>>n>>m>>k;
    ans = n * m;
    for(int o=0;o<=n;o++)
        for(int i=0;i<=m;i++)
            v[o].push_back(0);
    queue<info> qu;
    for(int i=0;i<k;i++){
        cin>>x>>y;
        info p;
        p.x = x;
        p.y = y;
        p.d = d;
        qu.push(p);
        v[x][y] = 1;
    }
    while(qu.size()!=0){
        while(qu.size()!=0 && qu.front().d == d){
            info tmp = qu.front();
            qu.pop();
            ans--;
            int xx[4] = {1,-1,0,0};
            int yy[4] = {0,0,1,-1};
            for(int i=0;i<4;i++){
                info p;
                p.x = tmp.x+xx[i];
                p.y = tmp.y+yy[i];
                p.d = d+1;
                if(p.x<=0 || p.y<=0 || p.x>n || p.y>m || v[p.x][p.y] == 1)
                    continue;
                qu.push(p);
                v[p.x][p.y] = 1;
            }
        }
        if(ans != 0)
            cout<<ans<<" ";
        else
            cout<<0<<endl;
        d++;
    }
    return 0;
}
