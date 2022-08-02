#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 200000 ;
const int R = 1000000000 ;

int main() {
	registerValidation();
	int n = inf.readInt(1, N) ; inf.readEoln() ;

	for(int i=0; i<n; ++i) {
		int h = inf.readInt(-R, R) ; inf.readSpace() ;
		int v = inf.readInt(-R, R) ; inf.readEoln() ;
	}
	inf.readEof() ;
}
