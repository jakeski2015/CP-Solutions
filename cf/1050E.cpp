#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n; ll k;
    cin >> n >> k;
    vector<ll> a;
    map<ll, ll> maxOccurrences;
    for(ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        a.push_back(temp);
        maxOccurrences[temp]++;
    }
    for (auto p : maxOccurrences) {
        ll num = p.first;
        ll occurrences = p.second;
        if (occurrences%k != 0) {
            cout << 0 << "\n";
            return;
        }
        //set maxOccurrences to the maximum occurences allowed in any awesome subarray
        maxOccurrences[num] = occurrences/k; 
    }

    map <ll, ll> window;
    ll r = 0;
    ll awesome = 0;
    for(ll l = 0; l < n; l++) {
        while(r < n and window[a[r]] != maxOccurrences[a[r]]) {
            window[a[r]]++;
            r++;
        }
        // forall i between l and r, a[l..r] is an awesome subarray
        awesome += r-l;
        window[a[l]]--;
    }
    cout << awesome << "\n";
}

int main() {
    ll t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}