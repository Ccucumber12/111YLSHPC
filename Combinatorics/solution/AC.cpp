#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

struct info {
    int op, a, b ;
} ;

int n, m ;
vector<int> v ;
vector<info> r ;

bool nexTo(int a, int b) {
    return (min(a, b)+1 == max(a, b)) ;
}

bool check() {
    int pos[11] ;
    for(int i=0; i<n; ++i)
        pos[v[i]] = i ;
    for(auto i:r) {
        if(i.op == 1) {
            if(!nexTo(pos[i.a], pos[i.b]))
                return false ;
        } else if(i.op == 2) {
            if(nexTo(pos[i.a], pos[i.b]))
                return false ;
        } else if(i.op == 3) {
            if(pos[i.a] > pos[i.b])
                return false ;
        }
    }
    return true ;
}

int main() {
    cin >> n >> m ;
    for(int i=1; i<=n; ++i)
        v.emplace_back(i);
    r.resize(m) ;
    for(auto &i:r)
        cin >> i.op >> i.a >> i.b ;
    
    int ans = 0 ;
    do {
        ans += check() ;
    } while(next_permutation(v.begin(), v.end())) ;
    cout << ans << endl ; 
}