#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll MOD = 1E9 + 7;

    ll t;
    cin >> t;
    vector<ll> tests;
    ll largestTest = 0;
    for(ll i = 0; i < t; i++) {
        ll test;
        cin >> test;
        tests.push_back(test);
        largestTest = max(largestTest, test);
    }

    vector<pair<ll,ll>> dp(largestTest + 1);
    dp[1] = (make_pair(1,1));
    for(ll i = 2; i <= largestTest; i++) {
        pair<ll, ll> prev = dp[i-1];
        pair<ll, ll> curr = make_pair(0,0);
        curr.first += 4*prev.first;
        curr.second += prev.first;
        curr.first += prev.second;
        curr.second += 2*prev.second;
        curr.first %= MOD;
        curr.second %= MOD;
        dp[i] = curr;
    }

    for(ll test : tests) {
        cout << (dp[test].first + dp[test].second)%MOD << "\n";
    }

    return 0;
}