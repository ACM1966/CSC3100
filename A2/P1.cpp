#include<bits/stdc++.h>
#define N 100001
using namespace std;
typedef long long ll;
int main(){
    ll M[N][N],record[N][2];
    /*
        record[i][0] means how much messages does the ith man sends
        record[i][1] means how much messages does the ith man receives
    */
    ll n,ans=-1;
    cin>>n;

/*
	for (int i=0;i<n;i++)
    	for(int j=0;j<n;j++)
    		M[i][j]=0;
    for (int i = 0; i < n; i++) {
        record[i][0] = 0;
        record[i][1] = 0;
    }
*/

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>M[i][j];
            if(M[i][j]==1){
                record[i][0]+=1;
                record[j][1]+=1;
            }
        }
	}
    for (int i=0;i<n;i++){
        if (record[i][0]==0 && record[i][1]==n-1){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
