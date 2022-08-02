#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 1000 ;
const int R = 100 ;

int main() {
	registerValidation();
	int n = inf.readInt(1, N) ; inf.readSpace() ;
	int c = inf.readInt(1, R) ; inf.readEoln() ;
	for(int i=0; i<n-1; ++i) {
		int k = inf.readInt(0, R) ;
		inf.readSpace() ;
	}
	int k = inf.readInt(0, R) ; inf.readEoln() ;
	inf.readEof() ;
}
