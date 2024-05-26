#include <bits/stdc++.h>
#define SIZE 100001
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll n;
ll colors[SIZE], ans[SIZE], bsize[SIZE];
deque<pair<ll, ll> > neighbors[SIZE];

void dfs(ll x, ll father, ll distance) {
    ll d1 = (MOD + distance) % MOD;
    if (colors[x - 1] == 1)
        ans[0] = (ans[0] + d1) % MOD;
    if (colors[x - 1] == 1)
        bsize[x - 1]++;

    for (ll i = 0; i < neighbors[x].size(); i++) {
        ll y = neighbors[x][i].first;
        ll e = neighbors[x][i].second;

        if (y != father) {
            dfs(y, x, e + distance);
            bsize[x - 1] += bsize[y - 1];
        }
    }
}

void renew(ll x, ll father) {
    for (ll i = 0; i < neighbors[x].size(); i++) {
        ll y = neighbors[x][i].first;
        ll e = neighbors[x][i].second;

        if (y != father) {
            ans[y - 1] = (MOD + ans[x - 1] + (MOD + e * bsize[0]) % MOD - (MOD + 2 * e * bsize[y - 1]) % MOD) % MOD;
            renew(y, x);
        }
    }
}

int main() {
    cin >> n;
    for (ll t = 0; t < n; t++) {
        cin>>colors[t];
    }
    neighbors[0].push_back({1, 0});
    for (ll k = 0; k < n - 1; k++) {
        ll x, y, distance;
        cin >> x >> y >> distance;
        neighbors[x].push_back({y, distance});
        neighbors[y].push_back({x, distance});
    }
    dfs(1, 0, 0);
    renew(1, 0);
    for (ll i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}

