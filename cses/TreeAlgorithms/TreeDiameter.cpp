#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<ll,vector<ll>> adj;
ll overallMax = 0;

ll dfs(ll curr, ll prev) {
    priority_queue<ll> maxes;
    for(ll v : adj[curr]) {
        if (v != prev) {
            maxes.push(-1 * dfs(v,curr));
            if (maxes.size() > 2) {
                maxes.pop();
            }
        }
    }
    ll ans;
    ll toret;
    if (maxes.size() == 0) {
        toret = 1;
        ans = toret;
    } else if (maxes.size() == 1) {
        toret = (-1 * maxes.top()) + 1;
        ans = toret;
    } else {
        ans = (-1 * maxes.top()) + 1;
        maxes.pop();
        toret = (-1 * maxes.top()) + 1;
        ans += (-1 * maxes.top());
    }
    overallMax = max(ans, overallMax);
    return toret;
}

int main() {
    ll n;
    cin >> n;
    for(ll i = 0; i < n - 1; i++) {
        ll u; ll v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    cout << overallMax - 1;
}