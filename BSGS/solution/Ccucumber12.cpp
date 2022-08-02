#include <iostream>
#include <map>
#include <set>
using namespace std ;

using ll = long long ;

int main() {
    int a, b, p ;
    cin >> a >> b >> p ;
    int m = 1 ;
    while(m * m < p)
        m++ ;
    
    ll am = 1 ;
    for(int i=0; i<m; ++i)
        am = (am * a) % p ;

    map<int,int> mp ;
    ll tmp = 1 ;
    for (int i=1; i<=m; ++i) {
        tmp = (tmp * am) % p ;
        mp[tmp] = i ;
    }

    tmp = b % p ;
    for (int i=0; i<m; ++i) {
        if (mp[tmp]) {
            int ans = m * mp[tmp] - i ;
            if (ans < 0)
                ans += p ;
            cout << ans << '\n';
            return 0 ;
        }
        tmp = (tmp * a) % p ;
    }
}