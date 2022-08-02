#include "testlib.h"
#include <iostream>
#include <random>
#include <algorithm>
using namespace std;
int main(int argc,char *argv[])
{
	registerGen(argc, argv,1);
	int L_C = atoi(argv[1]);
	int H_C = atoi(argv[2]);
  int L_K = atoi(argv[3]);
	int H_K = atoi(argv[4]);
  int cw = atoi(argv[5]);
  int tmpN;
	int tmpM;
	int tmpK;
  long long tmpN_M;
	while(true){
		  tmpN = rnd.wnext(L_C,H_C,cw);
      if(L_C != 1)
	      tmpM = rnd.wnext(L_C,H_C,cw);
	    else
        tmpM = 1;
      tmpN_M = tmpN;
      tmpN_M *= tmpM;
		  if(cw == 3){
        while(tmpN_M > 1000000){
          if(tmpN > 800)
            tmpN /= 10;
          else
            tmpM /= 10;
          tmpN_M = tmpN;
          tmpN_M *= tmpM;
        }
      }
      if(tmpN_M <= 1000000)
			    break;
	}
  cout<<tmpN<<" "<<tmpM<<endl;
  vector< pair<int,int> > v;
  for(int i=1;i<=tmpN;i++)
    for(int o=1;o<=tmpM;o++)
      v.push_back(make_pair(i,o));
  shuffle(v.begin(),v.end());
  if(H_K == 1)
    tmpK = rnd.next(1,1);
  else
    tmpK = rnd.wnext(1,min(tmpN * tmpM , H_K),cw);
  cout<<tmpK<<endl;
  for(int i=0;i<tmpK;i++)
    cout<<v[i].first<<" "<<v[i].second<<endl;
  return 0;
}