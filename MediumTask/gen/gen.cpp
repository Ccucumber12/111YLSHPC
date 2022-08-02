#include "testlib.h"
#include <bits/stdc++.h>
using namespace std ;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1) ;
  int n = atoi(argv[1]) ;
  int r = atoi(argv[2]) ;
  int w = atoi(argv[3]) ;

  printf("%d\n", n) ;
  for(int i=0; i<n; ++i) {
    int k = rnd.wnext(-r, r, w) ;
    printf("%d", k) ;
    if(i == n-1)
      printf("\n") ;
    else
      printf(" ") ;
  }
}