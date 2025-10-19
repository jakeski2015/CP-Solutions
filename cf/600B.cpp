#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n; ll m; cin >> n >> m;
    map<ll,ll> a; vector<ll> b;
    for(ll i = 0; i < n; i++) {ll ai; cin >> ai; a[ai]++;}
    for(ll i = 0; i < m; i++) {ll bi; cin >> bi; b.push_back(bi);}
    auto curr = ++a.begin();
    auto prev = a.begin();
    for(; curr != a.end(); curr++) {
        a[curr->first] += prev->second;
        prev = curr;
    }
    for(ll bj : b) {
        auto ans = a.upper_bound(bj);
        ll toret = 0;
        if (ans != a.begin()){
            toret = (--ans)->second;
        }
        cout << toret << " ";
    }
}