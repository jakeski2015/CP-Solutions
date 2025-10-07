#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dfs(ll curr, ll goal, ll d) {
    //cout << curr << " -> " << goal << "\n";
    if(curr >= goal) {
        return curr - goal;
    }
    if (goal%2 == 0) {
        ll res = min(1 + dfs(curr, goal/2, d + 1), 1 + dfs(curr * 2, goal, d + 1));
        return res;
    } else {
        ll res = min(2 + dfs(curr, ceil(goal/2.0), d + 1), 1 + dfs(curr * 2, goal, d + 1));
        return res;
    }
    
}

int main() {
    ll n; ll m;
    cin >> n >> m;
    cout << dfs(n,m, 0);
}