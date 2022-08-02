#include<bits/stdc++.h>
using namespace std;
map<long long,long long> ma;
int main(){
    long long a,p,b;
    cin>>a>>b>>p;
    long long m = sqrt(p)+1;
    b %= p;
    a %= p;    
    long long tmp=1,ttmp=1;
    for(int i=1;i<=m;i++){
        tmp *= a;
        tmp %= p;
        ma[(b*tmp)%p] = i;
    }
    ttmp = tmp;
    for(int i=1;i<=m;i++){
        if(ma[ttmp] != 0){
            cout<<(i*m-ma[ttmp])%p<<endl;
            break;
        }
        ttmp *= tmp;
        ttmp %= p;
    }
    return 0;
}
