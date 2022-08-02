#include "testlib.h"
#include <bits/stdc++.h>
using namespace std ;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1) ;
  int n = atoi(argv[1]) ;
  int c = atoi(argv[2]) ;
  int r = atoi(argv[3]) ;
  int w = atoi(argv[4]) ;
  printf("%d %d\n", n, c) ;
  for(int i=0; i<n; ++i) {
    int k = rnd.wnext(0, r, w) ;
    printf("%d", k) ;
    if(i == n-1)
      printf("\n") ;
    else
      printf(" ") ;
  }
}