#include <iostream>
using namespace std ;

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;
    int n ;
    long long ipt, ans = 0 ;

    cin >> n ;
    while(n--) {
        cin >> ipt ;
        ans += ipt ;
    }
    cout << ans << endl ;
}