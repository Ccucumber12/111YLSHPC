#include <iostream>
#include <vector>
#include <queue>
using namespace std ;

int main() {
    int n, m, k ;
    cin >> n >> m >> k;

    vector<vector<int>> v(n, vector<int>(m)) ;
    queue<pair<int,int>> qu ;
    for(int i=0; i<k; ++i) {
        int x, y ;
        cin >> x >> y ;
        x--; y--; 
        qu.push({x, y}) ;
        v[x][y] = 1 ;
    }

    int ans = n * m ;
    int dx[4] = {0, 1, 0, -1} ;
    int dy[4] = {1, 0, -1, 0} ;
    while(qu.size()) {
        int l = qu.size() ;
        while(l--) {
            pair<int,int> t = qu.front() ;
            qu.pop() ;
            --ans ;
            for(int i=0; i<4; ++i) {
                int nx = t.first + dx[i] ;
                int ny = t.second + dy[i] ;
                if (0 <= nx && nx < n && 0 <= ny && ny < m && v[nx][ny] == 0) {
                    v[nx][ny] = 1 ;
                    qu.push({nx, ny}) ;
                }
            }
        }
        cout << ans << ' ' ;
    }
    cout << '\n' ;
}