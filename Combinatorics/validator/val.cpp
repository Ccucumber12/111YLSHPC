#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 10 ;
const int M = 10 ;

int main() {
	registerValidation();
	int n = inf.readInt(1, N) ; inf.readSpace() ;
	int m = inf.readInt(0, M) ; inf.readEoln() ;

	for (int i=0; i<m; ++i) {
		int op = inf.readInt(1, 3) ; inf.readSpace() ;
		int a = inf.readInt(1, n) ; inf.readSpace() ;
		int b = inf.readInt(1, n) ; inf.readEoln() ;

		ensuref(a != b, "A equals to B!\n") ;
	}
	inf.readEof() ;
}
