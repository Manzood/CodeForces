#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;

    int size = 64;
    while (size >= n) size /= 2;
    int ans = 0;

    while (size >= 1) {
        vector<int> s1, s2;
        int cur = 0;
        bool f = 0;
        for (int i = 0; i < n; i++) {
            if (f) {
                s2.push_back(i + 1);
            } else {
                s1.push_back(i + 1);
            }

            cur++;
            if (cur == size) {
                cur = 0;
                f ^= 1;
            }
        }

        cout << (int)s1.size() << " " << (int)s2.size() << " ";
        for (auto x : s1) {
            cout << x << " ";
        }
        for (auto x : s2) {
            cout << x << " ";
        }
        cout << endl;

        int val;
        cin >> val;
        if (val == -1) exit(0);
        ans = max(ans, val);

        size /= 2;
    }

    cout << "-1 " << ans << endl;
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
