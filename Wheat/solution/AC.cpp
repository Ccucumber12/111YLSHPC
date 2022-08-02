#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

using ll = long long ;

void discrete(vector<int> &v) {
    vector<int> tmp = v ;
    sort(tmp.begin(), tmp.end()) ;
    tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin()) ;
    for(auto &i:v)
        i = (lower_bound(tmp.begin(), tmp.end(), i) - tmp.begin() + 1) ;
}

const int N = 200010 ;
int mxn = 1 ;
ll dp0[4*N], dp1[4*N] ;

void modify(ll arr[], int idx, ll val) {
    idx += mxn - 1 ;
    arr[idx] = max(arr[idx], val) ;
    while(idx > 1) {
        idx >>= 1 ;
        arr[idx] = max(arr[idx*2], arr[idx*2+1]) ;
    }
}

ll query(ll arr[], int l, int r, int lb, int rb, int idx) {
    if(l > r) return 0 ;
    if(l <= lb && rb <= r) 
        return arr[idx] ;
    
    int mid = (lb + rb) >> 1 ;
    ll ans = 0 ;
    if(l <= mid) ans = max(ans, query(arr, l, r, lb, mid, idx*2)) ;
    if(mid <  r) ans = max(ans, query(arr, l, r, mid+1, rb, idx*2+1)) ;
    return ans ;
}

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(0) ; cout.tie(0) ;
    int n ;

    cin >> n ;
    vector<int> h(n), v(n) ;
    for(int i=0; i<n; ++i)
        cin >> h[i] >> v[i] ;
    
    discrete(h) ;

    while(mxn < n)
        mxn <<= 1 ;
    
    for(int i=0; i<n; ++i) {
        modify(dp0, h[i], query(dp1, h[i]+1, mxn, 1, mxn, 1) + v[i]) ;
        modify(dp1, h[i], query(dp0, 1, h[i]-1, 1, mxn, 1) + v[i]) ;
    }
    cout << max(dp0[1], dp1[1]) << '\n' ;
}