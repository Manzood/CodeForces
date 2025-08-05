#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool check(string& ans, vector<int>& a) {
    int n = (int)a.size();
    vector<int> cur;
    int l = 0, r = n - 1;
    for (auto c : ans) {
        if (l > r) return false;
        if (c == 'L') {
            cur.push_back(a[l]);
            l++;
        } else {
            cur.push_back(a[r]);
            r--;
        }
    }

    for (int i = 1; i < (int)cur.size(); i++) {
        if (cur[i] <= cur[i - 1]) return false;
    }

    return true;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    string ans;
    for (int len = 1; len <= n; len++) {
        for (int mask = 0; mask < (1LL << len); mask++) {
            string cur;
            for (int i = 0; i < len; i++) {
                if (mask & (1LL << i)) {
                    cur += 'L';
                } else {
                    cur += 'R';
                }
            }

            if (check(cur, a)) {
                if ((int)ans.size() < (int)cur.size()) {
                    ans = cur;
                }
            }
        }
    }
    cout << (int)ans.size() << "\n";
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
