#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a,b,p,tmp=1;
    cin>>a>>b>>p;
    for(int i=1;i<=p;i++){
        tmp *= a;
        tmp %= p;
        if(tmp%p == b%p){
            cout<<i<<endl;
            break;
        }
    }
}