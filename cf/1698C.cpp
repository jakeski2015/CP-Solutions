#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a;
    ll posNums = 0; ll negNums = 0;
    map<ll, ll> counter;
    vector<ll> reconstructed;
    for(ll i = 0; i < n; i++) {
        ll ai;
        cin >> ai;
        a.push_back(ai);
        counter[ai]++;
        if (ai != 0) {
            ai < 0 ? negNums++ : posNums++;
        }
        if (counter[ai] <= 2) {
            reconstructed.push_back(ai);
        }
    }
    if (posNums >= 3 or negNums >= 3) {                    
        cout << "NO\n";                        
        return;
    }
    for(int i = 0; i < reconstructed.size(); i++) {
        for (int j = i + 1; j < reconstructed.size(); j++) {
            for(int k = j + 1; k < reconstructed.size(); k++) {
                if(counter.find(reconstructed[i] + reconstructed[j] + reconstructed[k]) == counter.end()) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++) {
        solve();
    }
}