#include <iostream>
using namespace std ;

int main() {
    int n ;
    long long ipt, ans = 0 ;

    cin >> n ;
    while(n--) {
        cin >> ipt ;
        ans += ipt ;
    }
    cout << ans << endl ;
}