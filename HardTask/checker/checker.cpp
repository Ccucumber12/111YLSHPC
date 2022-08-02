#include "testlib.h"
using namespace std;

const int R = 1000000000 ;

int main(int argc, char* argv[])
{
	registerTestlibCmd(argc, argv);
	long long a = ouf.readInt(-R, R) ;
	long long b = ouf.readInt(-R, R) ;
	long long c = ouf.readInt(-R, R) ;
	long long k = inf.readInt(-R, R) ; inf.readEoln() ; inf.readEof() ;
	if(a + b + c == k)
		quit(_ok);
	else
		quit(_wa);
}
