#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int queries = 0;
int query(int i, int x) {
    queries++;
    cout << "? " << i + 1 << " " << x << endl;
    int response;
    cin >> response;
    if (response == -1) exit(1);
    return response;
}

int ans = -1;
void check(vector<int>& a, int low, int high) {
    if (a.empty()) {
        ans = low;
        return;
    }

    int mask = 0;
    int cnt = 0;
    for (int bit = 30; bit >= 0; bit--) {
        int cur = 0;
        for (int i = low; i <= high; i++) {
            if ((mask | (1LL << bit)) & i) cur++;
        }
        if (cur == (high - low + 1) || cur == cnt) continue;

        mask |= (1LL << bit);
        cnt = cur;
        if (cnt >= (high - low + 1) / 2) {
            break;
        }
    }
    assert(cnt < (high - low) + 1);

    int found = 0;
    vector<int> lower, higher;
    for (auto ind : a) {
        int cur = query(ind, mask);
        found += cur;
        if (cur) {
            higher.push_back(ind);
        } else {
            lower.push_back(ind);
        }
    }

    if (found == cnt) {
        int mid = low;
        for (int i = low; i < high; i++) {
            if (i & mask) continue;
            mid = i;
        }
        assert(lower.size() < a.size());
        assert(mid - low == (int)lower.size());
        a = lower;
        check(a, low, mid);
    } else {
        int mid = high;
        for (int i = high - 1; i >= low; i--) {
            if (i & mask) mid = i;
        }
        assert(higher.size() < a.size());
        assert(high - mid == (int)higher.size());
        a = higher;
        check(a, mid, high);
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;
    ans = -1;
    queries = 0;

    vector<int> a(n - 1);
    iota(a.begin(), a.end(), 0);
    check(a, 1, n);
    assert(queries <= 2 * n);

    cout << "! " << ans << endl;
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
