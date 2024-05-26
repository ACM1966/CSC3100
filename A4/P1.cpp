#include <bits/stdc++.h>
#define INF 1000001
using namespace std;

int T, n;
int fathers[INF];
int numChild[INF];

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        if (n == 1) {
            int c;
            cin >> c;
            if (c == 1) 
                cout << "YES" << endl;
            else 
                cout << "NO" << endl;
    	}
        else {
            for (int i = 0; i < INF; i++) 
                numChild[i] = 0; 
            int tmp;
            for (int i = 1; i < n; i++) {
                cin >> tmp;
                fathers[i] = tmp;
                numChild[tmp - 1]++;
            }
            stack<int> s;
            int cur, next;
            cin >> tmp;
            s.push(tmp);
            for (int i = 1; i < n; i++) {
                cur = s.top();
                cin >> next;
                if (fathers[next - 1] != cur) {
                    for (int j = i + 1; j < n; j++) {
                        cin >> tmp;
                    }
                    break;
                }
                numChild[cur - 1]--;
                if (numChild[next - 1] == 0) {
                    while (!s.empty() && numChild[cur - 1] == 0) {
                        s.pop();
                        if (s.empty())
                            break;
                        cur = s.top();
                    }
                } else {
                    s.push(next);
                }
            }
            if (s.empty())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}

