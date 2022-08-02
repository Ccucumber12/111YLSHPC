#include "testlib.h"
#include <bits/stdc++.h>
using namespace std ;

struct info {
  int a, b, c ;
} ;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1) ;
  int n = atoi(argv[1]) ;
  int m = atoi(argv[2]) ;
  int R = atoi(argv[3]) ;
  int cw = atoi(argv[4]) ;

  printf("%d %d\n", n, m) ;
  
  vector<int> hash(n) ;
  for(int i=0; i<n; ++i)
    hash[i] = i+1 ;
  shuffle(hash.begin(), hash.end()) ;

  vector<info> edges ;
  for (int i=1; i<n; ++i) {
    int a = i ;
    int b = rnd.next(i) ;
    int c = rnd.wnext(1, R, cw) ;
    edges.emplace_back(info{a, b, c}) ;
  }
  for (int i=n-1; i<m; ++i) {
    int a = rnd.next(n) ;
    int b = rnd.next(n) ;
    int c = rnd.wnext(1, R, cw) ;
    while(a == b)
      b = rnd.next(n) ;
    edges.emplace_back(info{a, b, c}) ;
  }
  shuffle(edges.begin(), edges.end()) ;

  for (auto i:edges) {
    if(rnd.next(2) == 0)
      swap(i.a, i.b) ;
    printf("%d %d %d\n", hash[i.a], hash[i.b], i.c) ;
  }
}