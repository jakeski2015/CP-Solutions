#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n; int m;
map<ll, vector<ll>> adj;
vector<int> ans;

bool dfs(ll u) {
    ll adjVal = ans[u]%2 + 1;
    bool res = true;
    for(ll v : adj[u]) {
        if (ans[v] != 0 && ans[v] != adjVal) {
            return false;
        } else if (ans[v] == 0) {
            ans[v] = adjVal;
            res = res && dfs(v);
        }
    }
    return res;
}

int main() {
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll u; ll v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // initialize empty vector for storing answers
    for(ll i = 0; i <= n; i++) {
        ans.push_back(0);
    }

    bool res = true;
    for(ll i = 1; i <= n; i++) {
        if (ans[i] == 0) {
            ans[i] = 1;
            res = res && dfs(i);
        }
    }
    if (!res) {
        cout << "IMPOSSIBLE";
    } else {
        for(ll i = 1; i <= n; i++) cout << ans[i] << " ";
    }
    return 0;
}