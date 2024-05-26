#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
int T;
ld r1,r2,d,ans;
int main(){
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>r1>>r2>>d;
		ld v=pow(r2,3)-pow(r1,3)+pow(r1-d,3);
		ld k1=pow(v,0.3333333333333);
		cout<<setprecision(10)<<(r2-k1)<<endl;
	}
	return 0;
}
