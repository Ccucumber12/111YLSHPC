#include<bits/stdc++.h>
using namespace std;
struct info{
    int x,y,d;
};

int main()
{
    int n,m,k,ans=0,x,y,d=1;
    cin>>n>>m>>k;
    ans = n * m;
    map< pair<int,int> ,int > ma;
    queue<info> qu;
    for(int i=0;i<k;i++){
        cin>>x>>y;
        qu.push(info{x,y,d});
        ma[make_pair(x,y)] = 1;
    }
    while(qu.size()!=0){
        while(qu.size()!=0 && qu.front().d == d){
            info tmp = qu.front();
            qu.pop();
            ans--;
            int xx[4] = {1,-1,0,0};
            int yy[4] = {0,0,1,-1};
            for(int i=0;i<4;i++){
                if(tmp.x+xx[i]<=0 || tmp.y+yy[i]<=0 || tmp.x+xx[i]>n || tmp.y+yy[i]>m || ma[make_pair(tmp.x+xx[i],tmp.y+yy[i])] == 1)
                    continue;
                qu.push(info{tmp.x+xx[i],tmp.y+yy[i],d+1});
                ma[make_pair(tmp.x+xx[i],tmp.y+yy[i])] = 1;
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
