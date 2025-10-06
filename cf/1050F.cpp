#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> grid;
    ll greatestM = 0;
    for(int i = 0; i < n; i++) {
        vector<ll> currRow;
        ll m;
        cin >> m;
        for(int j = 0; j < m; j++) {
            ll currVal;
            cin >> currVal;
            currRow.push_back(currVal);
        }
        greatestM = max(greatestM, m);
        grid.push_back(currRow);
    }
    
    ll i = 0;
    ll rowsUsed = 0;
    vector<ll> sol;
    while (i < greatestM) {
        // sort by leading digits starting at i
        sort(grid.begin()+rowsUsed, grid.end(), [i, greatestM](const vector<ll>& a, const vector<ll>& b) {
            if (a.size() < i) {
                return false;
            } else if (b.size() < i) {
                return true;
            }
            for(int j = i; j < greatestM; j++) {
                if (a.size() <= j) {
                    return true;
                } else if (b.size() <= j) {
                    return false;
                } else if (a[j] != b[j]) {
                    return a[j] < b[j];
                }
            }
            return true;
        });
        vector<ll> localAns = grid[rowsUsed];
        for(int j = i; j < localAns.size(); j++) {
            sol.push_back(localAns[j]);
        }
        i = localAns.size();
        rowsUsed++;

    }
    for(int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    cout << "\n";
}

int main() {
    ll t; 
    cin >> t;
    for(ll i = 0; i < t; i++) {
        solve();
    }
    return 0;
}