#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
map<ll, vector<ll>> adj;

int main() {
    cin >> n;
    for(ll i = 0; i < n - 1; i++) {
        ll u; ll v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<pair<ll,ll>> maxDistNodes;
    queue<tuple<ll,ll,ll>> q;
    maxDistNodes.push(make_pair(0,1));
    q.push(make_tuple(0,1,-1));
    while (!q.empty()) {
        tuple<ll,ll,ll> curr_tup = q.front();
        q.pop();
        ll depth = get<0>(curr_tup);
        ll u = get<1>(curr_tup);
        ll pred = get<2>(curr_tup);
        for(ll v : adj[u]) {
            if (v != pred) {
                q.push(make_tuple(depth - 1, v, u));
                maxDistNodes.push(make_pair(depth - 1, v));
                if (maxDistNodes.size() > 2) {
                    maxDistNodes.pop();
                }
            }
        }
    }
    for(ll i = 0; i < 2; i++) {
        cout << maxDistNodes.top().second << " : " << maxDistNodes.top().first << "\n";
        maxDistNodes.pop();
    }

    return 0;
}