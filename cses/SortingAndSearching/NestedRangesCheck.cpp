#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    map<pair<ll,ll>, ll> pairToIndex;
    ll n;
    cin >> n;
    vector<pair<ll, ll>> ranges;
    for(int i = 0; i < n; i++) {
        ll a; ll b;
        cin >> a >> b;
        ranges.push_back(make_pair(a,b));
        pairToIndex[make_pair(a,b)] = i;
    }
    sort(ranges.begin(), ranges.end(), [](pair<ll, ll> a, pair<ll,ll> b) {
        if (a.first == b.first) {
            return b.second < a.second;
        }
        return a.first < b.first;
    }); //sorts by left bound increasing, and if left bounds are equal then it sorts by right bound decreasing

    vector<ll> contains(n);
    ll minRight = ranges[n - 1].second;
    for(int i = n - 2; i >= 0; i--) {
        if (ranges[i].second >= minRight) {
            contains[pairToIndex[ranges[i]]] = 1;
        } else {
            minRight = ranges[i].second;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << contains[i] << " ";
    }
    cout << "\n";

    vector<ll> contained(n);
    ll maxRight = (*ranges.begin()).second;
    for(int i = 1; i < n; i++) {
        pair<ll,ll> curr = ranges[i];
        if(curr.second <= maxRight) {
            contained[pairToIndex[curr]] = 1;
        } else {
            maxRight = curr.second;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << contained[i] << " ";
    }
}