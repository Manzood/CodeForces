#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int query(int a, int b) {
    cout << "? " << a + 1 << " " << b + 1 << endl;
    int x;
    cin >> x;
    if (x == -1) exit(0);
    return x - 1;
}

// alternate binary search approach
void queryPath(int a, int b, vector<vector<int>>& adj, vector<bool>& found) {
    if (a == b) return;
    int x = query(a, b);
    if (x == a || x == b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
        found[a] = true;
        found[b] = true;
        return;
    }
    if (found[x]) {
        queryPath(x, b, adj, found);
    } else {
        queryPath(a, x, adj, found);
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;
    vector<bool> found(n, false);
    vector<vector<int>> adj(n), printed(n, vector<int>(n, false));
    found[0] = true;
    for (int i = 1; i < n; i++) {
        while (!found[i]) queryPath(0, i, adj, found);
    }
    cout << "!";
    for (int i = 0; i < n; i++) {
        for (auto x : adj[i]) {
            if (!printed[i][x]) {
                cout << " " << i + 1 << " " << x + 1;
                printed[i][x] = true;
                printed[x][i] = true;
            }
        }
    }
    cout << endl;
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
