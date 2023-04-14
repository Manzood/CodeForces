#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string a, b;
    cin >> a >> b;
    int n = (int)a.size();
    int m = (int)b.size();
    vector<vector<bool>> aprev(26, vector<bool>(26, false));
    vector<vector<bool>> bprev(26, vector<bool>(26, false));
    for (int i = 1; i < n; i++) {
        aprev[a[i] - 'a'][a[i - 1] - 'a'] = true;
    }
    for (int i = 1; i < m; i++) {
        bprev[b[i] - 'a'][b[i - 1] - 'a'] = true;
    }
    bool ans = false;
    string out;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (aprev[i][j] && bprev[i][j]) {
                ans = true;
                out = "*";
                out += (char)j + 'a';
                out += (char)i + 'a';
                out += '*';
            }
        }
    }
    if (!ans) {
        if (a[0] == b[0]) {
            ans = true;
            out = a[0];
            out += "*";
        } else if (a[n - 1] == b[m - 1]) {
            ans = true;
            out = "*";
            out += a[n - 1];
        }
    }
    if (ans) {
        printf("YES\n");
        cout << out << "\n";
    } else {
        printf("NO\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
