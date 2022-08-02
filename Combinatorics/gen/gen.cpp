#include "testlib.h"
#include <bits/stdc++.h>
using namespace std ;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1) ;
  int n = atoi(argv[1]) ;
  int m = atoi(argv[2]) ;

  cout << n << ' ' << m << endl ;
  for(int i=0; i<m; i++) {
    int op = rnd.next(1, 3) ;
    int a = rnd.next(1, n) ;
    int b = rnd.next(1, n) ;
    while(a == b)
      b = rnd.next(1, n) ;
    cout << op << ' ' << a << ' ' << b << endl ;
  }
}