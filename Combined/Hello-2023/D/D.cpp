#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void getNGE(vector<int>& a, vector<int>& output, int n) {
    stack<pair<int, int>> s;
    s.push({a[0], 0});
    for (int i = 1; i < n; i++) {
        if (s.empty()) {
            s.push({a[i], i});
            continue;
        }
        while (s.empty() == false && s.top().first < a[i]) {
            // cout << s.top() << " --> " << arr[i] << endl;
            output[s.top().second] = i;
            s.pop();
        }
        s.push({a[i], i});
    }
    while (s.empty() == false) {
        // cout << s.top() << " --> " << -1 << endl;
        output[s.top().second] = n;
        s.pop();
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    bool ans = true;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        if (a[i] < b[i]) ans = false;
    }
    int m;
    scanf("%lld", &m);
    vector<int> x(m);
    map<int, int> mp;
    for (int i = 0; i < m; i++) {
        scanf("%lld", &x[i]);
        mp[x[i]]++;
    }
    vector<int> nge(n);
    getNGE(b, nge, n);
    map<int, int> cut;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        if (cut.count(b[i]) && cut[b[i]] >= i) continue;
        // try to cut it
        if (mp[b[i]] == 0) {
            ans = false;
            break;
        }
        mp[b[i]]--;
        cut[b[i]] = nge[i] - 1;
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
