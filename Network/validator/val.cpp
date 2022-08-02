#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 100000 ;
const int M = 200000 ;
const int R = 100 ;

vector<int> G[N+10] ;
bool vis[N+10] ;

void dfs(int x) {
	vis[x] = true ;
	for(auto i:G[x]) {
		if(!vis[i])
			dfs(i) ;
	}
}

int main() {
	registerValidation();
	int n = inf.readInt(1, N) ; inf.readSpace() ;
	int m = inf.readInt(1, M) ; inf.readEoln() ;

	for(int i=0; i<m; ++i) {
		int a = inf.readInt(1, N) ; inf.readSpace() ;
		int b = inf.readInt(1, N) ; inf.readSpace() ;
		int c = inf.readInt(1, R) ; inf.readEoln() ;
		ensuref(a != b, "A is equal to B!\n") ;
		G[a].emplace_back(b) ;
		G[b].emplace_back(a) ;
	}

	dfs(1) ;
	bool flag = true ;
	for(int i=1; i<=n; ++i) 
		flag &= vis[i] ;
	ensuref(flag, "Graph not connected!\n") ;
	inf.readEof() ;
}
