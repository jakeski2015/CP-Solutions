#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

int main() {
    int n;
    vector<int> xs;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        xs.push_back(x);
    }

    vector<int> sol;
    unordered_map<pair<int, int>, int> c;
    void dfs(int total, int i) {
        if (c.contains(pair<int,int>(total, i))) {
            return c[pair<int,int>(total,i)]
        }
        if (i == n) {
            c[pair<int,int>(total,i)] = total;
            sol.push_back(total);
            return total;
        } else {
            
        }
    }

    dfs(0,0);
    for (int a : sol) {
        cout << a;
    }
    return 0;
}