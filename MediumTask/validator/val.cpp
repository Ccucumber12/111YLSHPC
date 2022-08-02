#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 5000000 ;
const int R = 1000000000 ;

int main() {
	registerValidation();
	int n = inf.readInt(1, N) ; inf.readEoln() ;
	for (int i=0; i<n; ++i) {
		int k = inf.readInt(-R, R) ;
		if(i == n-1)
			inf.readEoln() ;
		else
			inf.readSpace() ;
	}
	inf.readEof() ;
}
