#include<bits/stdc++.h>
#define INF 10001
using namespace std;

int main() {
    int N, w;
    cin >> N >> w;
    int A[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            if (A[i][j] > w ||A[i][j]==0) {
                A[i][j] = w; 
            }
        }
    }
    int dist[N];
    bool visited[N];
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[0] = 0; 
    int ans = w;
    for (int i = 0; i < N; i++) {
        int u = -1;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }
        visited[u] = true; 
        ans += dist[u]; 
        for (int v = 0; v < N; v++)
            dist[v] = min(dist[v], A[u][v]);
    }
    cout << ans << endl;
    return 0;
}

