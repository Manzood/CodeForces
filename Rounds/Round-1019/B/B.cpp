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
    n++;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s += '0';
    reverse(s.begin(), s.end());
    int cost = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            cost++;
        }
        cost++;
    }
    vector<int> changes;
    for (int i = 2; i < n; i++) {
        if (s[i] != s[i - 1]) changes.push_back(i);
    }
    if ((int)changes.size() >= 3) {
        cost -= 2;
    } else if ((int)changes.size() == 2) {
        if (s[1] == '1') {
            cost -= 2;
        } else {
            cost--;
        }
    } else if ((int)changes.size() == 1 && s[1] == '1') {
        cost--;
    }
    printf("%lld\n", cost);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
