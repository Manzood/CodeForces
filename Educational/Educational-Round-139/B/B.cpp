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
    scanf("%lld", &n);
    string s;
    cin >> s;
    vector<vector<pair<bool, int>>> next(
        26, vector<pair<bool, int>>(26, {false, -1}));
    bool ans = false;
    for (int i = 0; i < n - 1; i++) {
        if (next[s[i] - 'a'][s[i + 1] - 'a'].first &&
            next[s[i] - 'a'][s[i + 1] - 'a'].second != i - 1) {
            if (test == 3) debug(i);
            ans = true;
        } else if (!next[s[i] - 'a'][s[i + 1] - 'a'].first) {
            next[s[i] - 'a'][s[i + 1] - 'a'].first = true;
            next[s[i] - 'a'][s[i + 1] - 'a'].second = i;
        }
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
