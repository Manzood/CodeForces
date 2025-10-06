#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<int> z_function(vector<int> s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    z[0] = n;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld", &a[i].first, &a[i].second);
    }

    vector<int> seq;
    for (int i = 0; i < m; i++) {
        int val = a[i].second - a[i].first;
        if (val < 0) val += n;
        if (i == 0) {
            seq.push_back(val);
        } else {
            int other = a[i].first - a[i - 1].second;
            if (other < 0) other += n;
            seq.push_back(other);
            seq.push_back(val);
        }
    }
    int val = a[0].first - a[m - 1].second;
    if (val < 0) val += n;
    seq.push_back(val);
    debug(seq);

    vector<int> z = z_function(seq);
    bool possible = false;

    int slen = (int)seq.size();
    for (int len = 1; len < slen; len++) {
        if (slen % len != 0) continue;
        bool found = true;
        for (int i = 0; i < slen; i += len) {
            if (z[i] < len) found = false;
        }

        if (found) {
            possible = true;
        }
    }

    printf(possible ? "Yes\n" : "No\n");
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
