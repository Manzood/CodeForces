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
    bool ans = false;
    int ptr = 0;
    string s;
    cin >> s;
    vector<bool> a(4);
    while (ptr < n && (s[ptr] == 'm' || s[ptr] == 'M')) {
        a[0] = true;
        ptr++;
    }
    while (ptr < n && (s[ptr] == 'e' || s[ptr] == 'E')) {
        a[1] = true;
        ptr++;
    }
    while (ptr < n && (s[ptr] == 'o' || s[ptr] == 'O')) {
        a[2] = true;
        ptr++;
    }
    while (ptr < n && (s[ptr] == 'w' || s[ptr] == 'W')) {
        a[3] = true;
        ptr++;
    }
    if (ptr == n && a[0] == true && a[1] == true && a[2] == true &&
        a[3] == true)
        ans = true;
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
