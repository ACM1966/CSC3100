#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string smallest(const string& num,ll m) {
    deque<char> stack;
    for (char c : num) {	// while the latest number is smaller than top number
        while ((stack.empty()==false) && m>0 && stack.back()>c) { 
            stack.pop_back();
            m--;
        }
        stack.push_back(c);
    }
    
    while (m > 0) {		// while the front num is still 0, then delete it
        stack.pop_back();
        m--;
    }
    
    string ans;
    bool first_0 = true;	
    for (char c: stack) {
        if (first_0 && c=='0') 
			continue;
        else 
			first_0 = false;
        ans.push_back(c);
    }
    
    if(ans.empty()==true)
    	return "0";
    else
    	return ans;
    
}

int main() {
    string num;
    int m;
    cin>>num>>m;
    cout<<smallest(num, m) <<endl;
    return 0;
}

