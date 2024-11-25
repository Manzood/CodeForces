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
    set<pair<char, char>> st;
    for (int i = 1; i < n; i++) {
        pair<char, char> tmp;
        tmp.first = s[i - 1];
        tmp.second = s[i];
        st.insert(tmp);
    }
    printf("%lld\n", (int)st.size());
}
int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
