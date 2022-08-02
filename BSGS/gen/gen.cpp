#include "testlib.h"
#include <iostream>
using namespace std;
int gcd(int x,int y)
{
	if(y == 0)
		return x;
	return gcd(y,x%y);
}
int AC(int a,int b,int p)
{
	long long m = sqrt(p)+1;
    map<long long,long long> ma;
    long long tmp=1,ttmp=1;
	b %= p;
    a %= p;
    for(int i=1;i<=m;i++){
        tmp *= a;
        tmp %= p;
        ma[(b*tmp)%p] = i;
    }
    ttmp = tmp;
    for(int i=1;i<=m;i++){
        if(ma[ttmp]!=0)
            return 1;
        ttmp *= tmp;
        ttmp %= p;
    }
	return 0;
}
int main(int argc,char *argv[])
{
	registerGen(argc, argv,1);
	int L_A = atoi(argv[1]);
	int H_A = atoi(argv[2]);
  int L_P = atoi(argv[3]);
	int H_P = atoi(argv[4]);
  int cw = atoi(argv[5]);
  int tmpA;
	int tmpB;
	int tmpP;
	while(true){
		  tmpA = rnd.wnext(L_A,H_A,cw);
	    tmpB = rnd.wnext(L_A,H_A,cw);
	    tmpP = rnd.wnext(L_P,H_P,cw);
		  if(gcd(tmpA,tmpP)==1 && AC(tmpA,tmpB,tmpP) == 1 && tmpP != 1)
			    break;
	}
  cout<<tmpA<<" "<<tmpB<<" "<<tmpP<<endl;
}