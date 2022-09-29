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
    string s, t;
    cin >> s >> t;
    vector<pair<char, char>> a;
    map<pair<char, char>, int> mp;
    for (int i = 0; i < n; i++) {
        a.push_back(make_pair(s[i], t[n - i - 1]));
        mp[a[i]]++;
        if (s[i] != t[n - i - 1]) mp[make_pair(t[n - i - 1], s[i])]++;
    }
    int odd = 0;
    bool ans = true;
    bool equal = false;
    // debug(a);
    for (auto x : mp) {
        if (x.second & 1) {
            odd++;
            if (x.first.first == x.first.second) equal = true;
        }
    }
    if (n & 1) {
        if (odd != 1 || !equal) ans = false;
    } else {
        if (odd) ans = false;
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
