#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<ll,vector<ll>> adj;
set<ll> used;
map<pair<ll, bool>, ll> cache;
int dfs(ll curr, ll pred, bool include) {
    pair<ll,bool> cacheKey = make_pair(curr,include);
    if(cache.find(cacheKey) != cache.end()) {
        return cache[cacheKey];
    }

    ll localSum = 0;
    for(ll v : adj[curr]) {
        if (v != pred) {
            localSum += 1 + dfs(v, curr, true);
        }
    }
    if (include) {
        ll localMax = -1;
        for(ll v : adj[curr]) {
            ll currSum = localSum;
            if (v != pred) {
                currSum -= (1 + dfs(v,curr, true));
                currSum += dfs(v, curr, false);
                localMax = max(currSum, localMax);
            }
        }
        cache[cacheKey] = localMax;
        return localMax;
    }
    cache[cacheKey] = localSum;
    return localSum;
}

int main() {
    ll n;
    cin >> n;
    for(ll i = 0; i < n - 1; i++) {
        ll a; ll b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << max(1 + dfs(1,-1,true), dfs(1,-1,false));
}