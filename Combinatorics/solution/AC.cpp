#include <iostream>
#include <vector>
using namespace std ;
using ll = long long ;

struct info {
  int op, a, b ;
} ;
vector<info> v ;
int n, m ;
int use[20], cur[20] ;

ll ans = 0 ;
bool check(int x) {
  for(auto i:v) {
    if(i.op == 1 && x > 0) {
      if (i.a == cur[x-1]) {
        if ((i.b != cur[x]) && (x == 1 || i.b != cur[x-2]))
          return false;
      } else if(i.b == cur[x-1]) {
        if ((i.a != cur[x]) && (x == 1 || i.a != cur[x-2]))
          return false ;
      }
    } else if (i.op == 2 && x > 0) {
      if (min(i.a, i.b) == min(cur[x], cur[x-1]) && max(i.a, i.b) == max(cur[x], cur[x-1]))
        return false ;
    } else if (i.op == 3) {
      if (i.b == cur[x]) {
        bool flag = false ;
        for (int j=0; j<x; ++j)
          flag |= (i.a == cur[j]) ;
        if (!flag)
          return false ;
      }
    }
  }
  return true ;
}

void backtrack(int x) {
  if(x == n) {
    ++ans ;
    return ;
  }
  for(int i=1; i<=n; ++i) {
    if(use[i]) continue ;
    cur[x] = i ;
    if(check(x)) {
      use[i] = true ;
      backtrack(x + 1) ;
      use[i] = false ;
    }
  }
}

int main() {
  cin >> n >> m ;
  v.resize(m) ;
  for(auto &i:v) cin >> i.op >> i.a >> i.b ;

  backtrack(0) ; 
  cout << ans << endl ;
}