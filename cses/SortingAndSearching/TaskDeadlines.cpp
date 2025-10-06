#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<pair<ll,ll>> tasks;
    for(ll i = 0; i < n; i++) {
        ll dur; ll dead;
        cin >> dur >> dead;
        tasks.push_back(make_pair(dur,dead));
    }
    sort(tasks.begin(), tasks.end());
    ll f_im1 = 0;
    ll total = 0;
    for(ll i = 0; i < n; i++) {
        ll f_i = f_im1 + tasks[i].first;
        ll dmf = tasks[i].second - f_i;
        total += dmf;
        f_im1 = f_i;
    }
    cout << total;
}