#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
vector<ll> ans;
map<ll,vector<ll>> adj;

int dfs(ll u) {
    if (adj.find(u) != adj.end()) {
        ll count = 0;
        for (ll v : adj[u]) {
            count += 1 + dfs(v);
        }
        ans[u] = count;
        return count;
    }
    ans[u] = 0;
    return 0;
}

int main() {
    cin >> n;
    ans.push_back(-1);
    for(ll i = 2; i < n + 1; i++) {
        ans.push_back(-1);
        ll u;
        cin >> u;
        adj[u].push_back(i);
    }
    dfs(1);
    for(ll i = 1; i < n + 1; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}