#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll x; ll n;
    cin >> x >> n;
    priority_queue<ll, vector<ll>, greater<ll>> heap;
    for(ll i = 0; i < n; i++) {
        ll num;
        cin >> num;
        heap.push(num);
    }
    ll total = 0;
    while (heap.size() >= 2) {
        ll curr = 0;
        curr += heap.top();
        heap.pop();
        curr += heap.top();
        heap.pop();
        total += curr;
        heap.push(curr);
    }
    cout << total;
    return 0;
}