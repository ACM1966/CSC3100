#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll numA=0; ll numB=0;
int main(){
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]=='O')	
			continue;
		else if(s[i]=='A')
			numA++; 
		else if(s[i]=='B')
			numB++;
	}
	cout<<"A:"<<numA<<endl;
	cout<<"B:"<<numB<<endl;
	if(numA==numB)
		cout<<"Draw!"<<endl;
	else if(numA>numB)
		cout<<"A wins!"<<endl;
	else if (numA<numB)
		cout<<"B wins!"<<endl;
	return 0;
}
