#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n; ll m;
    cin >> n >> m;
    ll kmax = (n - (m-1))*((n - (m-1))-1)/2;
    ll kmin = 0;
    ll numTeamsWithMore = n%m;
    ll numTeamsWithLess = m - n%m;
    ll peopleOnTeamWithMore = n/m + 1;
    ll peopleOnTeamWithLess = n/m;
    kmin += numTeamsWithMore * (peopleOnTeamWithMore * (peopleOnTeamWithMore - 1)/2);
    kmin += numTeamsWithLess * (peopleOnTeamWithLess * (peopleOnTeamWithLess - 1)/2);
    cout << kmin << " " << kmax;
}