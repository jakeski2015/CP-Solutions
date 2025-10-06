#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {    
    vector<bool> ans;
    for(int i = 0; i <= 1E6; i++) {
        ans.push_back(true);
    }
    ans[0] = false;
    ans[1] = false;
    for(int i = 2; i <= 1E6; i++) {
        if (ans[i]) {
            for(int j = i + i; j <= 1E6; j += i) {
                ans[j] = false;
            }
        }
    }

    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++) {
        ll test;
        cin >> test;
        cout << (ans[test] ? "YES" : "NO") << "\n";
    }
    return 0;
}