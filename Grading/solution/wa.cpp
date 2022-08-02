#include <iostream>
using namespace std ;

int main() {
    int n, c ;
    cin >> n >> c ;
    for(int i=0; i<n; ++i) {
        int k ;
        cin >> k ;
        cout << k + c << ' ' ;
    }
}