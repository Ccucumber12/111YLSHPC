#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

using ll = long long ;

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(0) ; cout.tie(0) ;

    int n ;

    cin >> n ;
    vector<int> h(n), v(n) ;
    for(int i=0; i<n; ++i)
        cin >> h[i] >> v[i] ;
    
    vector<ll> dp0(n), dp1(n) ;
    for(int i=0; i<n; ++i) {
        dp0[i] = max(dp0[i], 1LL * v[i]) ;
        dp1[i] = max(dp1[i], 1LL * v[i]) ;
        for(int j=0; j<i; ++j) {
            if(h[j] > h[i])
                dp0[i] = max(dp0[i], dp1[j] + v[i]) ;
            if(h[j] < h[i])
                dp1[i] = max(dp1[i], dp0[j] + v[i]) ;
        }
    }
    ll ans = 0 ;
    for(int i=0; i<n; ++i)
        ans = max({ans, dp0[i], dp1[i]}) ;
    cout << ans << '\n' ;
}