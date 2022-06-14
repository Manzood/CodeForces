#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<vector<int>> dirs = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

void solve([[maybe_unused]] int test) {
    vector <string> s(8);
    for (int i = 0; i < 8; i++) {
        cin >> s[i];
    }
    int ansx = 0, ansy = 0;
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 7; j++) {
            bool found = true;
            for (auto x: dirs) {
                if (s[i + x[0]][j + x[1]] != '#') {
                    found = false;
                }
            }
            if (found) {
                ansx = i + 1;
                ansy = j + 1;
            }
        }
    }
    printf("%lld %lld\n", ansx, ansy);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
