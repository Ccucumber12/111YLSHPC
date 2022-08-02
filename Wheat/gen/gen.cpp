#include "testlib.h"
#include <bits/stdc++.h>
using namespace std ;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1) ;
  int n = atoi(argv[1]) ;
  int minH = atoi(argv[2]) ;
  int maxH = atoi(argv[3]) ;
  int minV = atoi(argv[4]) ;
  int maxV = atoi(argv[5]) ;

  
  printf("%d\n", n) ;
  for(int i=0; i<n; ++i) {
    int h = rnd.next(minH, maxH) ;
    int v = rnd.next(minV, maxV) ;
    printf("%d %d\n", h, v) ;
  }
}