#include<bits/stdc++.h>
#define N 100001
using namespace std;
typedef long long ll;

ll T,n,k,id,A[N];

bool cmp(ll a,ll b){
	if(id==1)
		return ( (a/k < b/k) || ((a/k == b/k)&&(a%k < b%k)) );
	else if(id==2)
		return ( (a/k > b/k) || ((a/k == b/k)&&(a%k < b%k)) );
	else if(id==3)
		return ( (a/k < b/k) || ((a/k == b/k)&&(a%k > b%k)) );
	else if(id==4)
		return ( (a/k > b/k) || ((a/k == b/k)&&(a%k > b%k)) );
	return false;
}

int main(){
	cin>>T;
	for (int i=0;i<T;i++){
		cin>>n>>k>>id;
		for (int j=0;j<n;j++){
			cin>>A[j];
		}
		sort(A,A+n,cmp);
		for (int j=0;j<n;j++){
			cout<< (A[j]/k) <<" "<< (A[j]%k) <<endl;
		}
		cout<<endl;
	}
	return 0;
}

