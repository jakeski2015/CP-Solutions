#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<char, ll> counter;

int main() {
    string s;
    cin >> s;
    
    for(char c : s) {
        counter[c]++;
    }

    ll n = s.size();
    char prev;
    string sol = "";
    for(ll i = 0; i < n; i++) {
        ll maxOccurences = ((n-i) + 1)/2;
        char mustUse;
        if ((n-i)%2 == 0) {
            maxOccurences++;
        }
        bool cont = false;
        for(auto p : counter) {
            if (p.second >= maxOccurences) {
                if ((n-i)%2 == 0) {
                    cout << -1;
                    return 0;
                } else {
                    sol += p.first;
                    counter[p.first]--;
                    if (counter[p.first] == 0) {
                        counter.erase(p.first);
                    }
                    prev = p.first;
                    cont = true;
                    break;
                }
            }
        }
        if (cont) {
            continue;
        }
        auto it = counter.begin();
        char use = (*it).first;
        if (prev and prev == use) {
            it++;
            if (it == counter.end()) {
                it = counter.begin();
            }
            use = (*it).first;
        }
        sol += use;
        counter[use]--;
        if (counter[use] == 0) {
            counter.erase(use);
        }
        prev = use;
    }
    cout << sol;
    return 0;
}