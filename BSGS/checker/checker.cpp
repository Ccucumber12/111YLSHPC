#include "testlib.h"
using namespace std;
long long qumi(long long x,long long y,long long m)
{
	long long a = 1;
	while(y!=0){
		if( y % 2 == 1){
			a *= x;
			a %= m;
			y--;
		}
		x *= x;
		x %= m;
		y /= 2;
	}
	return a;
}
int main(int argc, char* argv[])
{
	registerTestlibCmd(argc, argv);
	long long ans_ched = ouf.readInt(0,2147483647,"Answer not in [0,2147483647].");	
	long long in_A = inf.readInt();
	inf.readSpace();
	long long in_B = inf.readInt();
	inf.readSpace();
	long long in_P = inf.readInt();
	inf.readEoln();
	inf.readEof();
	if(qumi(in_A,ans_ched,in_P) == (in_B % in_P))
		quit(_ok);	
	else
		quit(_wa);
}
