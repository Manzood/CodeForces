#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void myshuffle(vector <int>& a, int start, int end) {
    vector<int> temp;
    for (int i = start; i <= end; i++) {
        temp.push_back(a[i]);
    }
    for (int i = start + 1; i <= end; i++) {
        a[i] = temp[i - start - 1];
    }
    a[start] = temp[(int) temp.size() - 1];
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector <int> p(n, 0);
    iota(p.begin(), p.end(), 1);
    int start = 0;
    int end = -1;
    bool possible = true;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            end = i;
        } else {
            if (start == i - 1) {
                possible = false;
                break;
            } else {
                // shuffle it
                assert(end > start);
                myshuffle(p, start, end);
                start = i;
                end = -1;
            }
        }
    }
    if (n == 1 || end <= start) possible = false;
    if (possible) {
        assert(end > start);
        if (end > -1) myshuffle(p, start, end);
        for (int i = 0; i < n; i++) {
            printf("%lld ", p[i]);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
