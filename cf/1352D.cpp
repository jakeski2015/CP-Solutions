#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n;
    cin >> n;
    vector<ll> candies;
    for(ll i = 0; i < n; i++) {
        ll candy;
        cin >> candy;
        candies.push_back(candy);
    }
    ll prevSizeOfCandies = 0;
    ll currSizeOfCandies = 0;
    ll l = 0; ll r = n - 1;
    bool alicesTurn = true;
    ll alicesTotal = 0;
    ll bobsTotal = 0;
    ll turns = 0;
    while(l <= r) {
        if (alicesTurn) {
            currSizeOfCandies += candies[l];
            alicesTotal += candies[l];
            l++;
        } else {
            currSizeOfCandies += candies[r];
            bobsTotal += candies[r];
            r--;
        }
        if (currSizeOfCandies > prevSizeOfCandies) {
            alicesTurn = not alicesTurn;
            prevSizeOfCandies = currSizeOfCandies;
            currSizeOfCandies = 0;
            turns++;
        }
    }
    if (currSizeOfCandies != 0 and currSizeOfCandies <= prevSizeOfCandies) {
        turns++;
    }
    cout << turns << " " << alicesTotal << " " << bobsTotal << "\n";
}

int main() {
    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
