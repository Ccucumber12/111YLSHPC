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

bool same(int a, int b, int pa, int pb) {
    return min(a, b) == min(pa, pb) && max(a, b) == max(pa, pb) ;
}

bool check() {
    for(auto i:r) {
        if(i.op == 1) {
            bool flag = false ;
            for (int j=0; j<n-1; ++j)
                if (same(i.a, i.b, v[j], v[j+1]))
                    flag = true ;
            if (!flag)
                return false ;
        } else if(i.op == 2) {
            bool flag = true ;
            for (int j=0; j<n-1; ++j)
                if (same(i.a, i.b, v[j], v[j+1]))
                    flag = false ;
            if (!flag)
                return false ;
        } else if(i.op == 3) {
            bool flag = false ;
            for (int j=0; j<n; ++j) {
                if (v[j] == i.a)
                    flag = true ;
                else if (v[j] == i.b) {
                    if (!flag)
                        return false ;
                }
            }
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