#include <iostream>
#include <vector>
using namespace std ;

using pii = pair<int,int> ;
const int N = 100010 ;
vector<pii> G[N] ;
bool vis[N] ;

int n ;

void dfs(int x, int l, int r) {
    vis[x] = true ;
    for(auto i:G[x]) 
        if(!vis[i.first] && l <= i.second && i.second <= r)
            dfs(i.first, l, r) ;
}

bool check(int l, int r) {
    for(int i=1; i<=n; ++i)
        vis[i] = false ;
    dfs(1, l, r) ;
    for(int i=1; i<=n; ++i)
        if(!vis[i])
            return false ;
    return true ;
}

int main() {
    ios::sync_with_stdio(false) ; 
    cin.tie(0) ; cout.tie(0) ;
    int m, maxc = 1 ;

    cin >> n >> m ;
    for(int i=0; i<m; ++i) {
        int a, b, c ;
        cin >> a >> b >> c ;
        G[a].emplace_back(b, c) ;
        G[b].emplace_back(a, c) ;
        maxc = max(maxc, c) ;
    }

    int ans = 100 ;
    int rb = 1 ;
    for(int i=1; i<=maxc; ++i) {
        while(rb <= maxc && !check(i, rb))
            ++rb ;
        if(rb > maxc)
            break ;
        ans = min(ans, rb - i) ;
    }
    cout << ans << '\n' ;
}