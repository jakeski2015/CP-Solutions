#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    map<string,ll> database;

    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        string name;
        cin >> name;
        if(database.find(name) == database.end()) {
            database[name] = 1;
            cout << "OK";
        } else {
            cout << name + to_string(database[name]);
            database[name]++;
        }
        cout << "\n";
    }
    return 0;
}