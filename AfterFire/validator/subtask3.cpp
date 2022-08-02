#include "testlib.h"
int main(){
	registerValidation();
	int in_N = inf.readInt(1,3000);
	inf.readSpace();
	int in_M = inf.readInt(1,300);
	inf.readEoln();
	if(in_N * in_M >1000000)
		return 1;
	int in_K = inf.readInt(1,in_N * in_M);
	inf.readEoln();
	for(int i=1; i<=in_K;i++){
		int in_x = inf.readInt(1,in_N);
		inf.readSpace();
		int in_y = inf.readInt(1,in_M);
		inf.readEoln();
	}
	inf.readEof();
	return 0;
}
