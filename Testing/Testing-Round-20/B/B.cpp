#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void firstRun() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n;
        scanf("%lld", &n);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                printf("0\n");
                break;
            } else if (a[i] == n) {
                printf("1\n");
                break;
            }
        }
    }
}

int query(int l, int r) {
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int response;
    cin >> response;
    return response;
}

// bad
// pair<int, int> search(int l, int r, int diff) {
//     int mid = (l + r) / 2;
//     pair<int, int> ret = {-1, -1};
//     if (l < r) return ret;
//     int response = query(l, r);
//     if (l == r) {
//         if (response)
//             return {l, l};
//         else
//             return ret;
//     }
//     if (response == 0) return ret;

//     // search left half
//     pair<int, int> r1 = search(l, mid, diff);
//     if (r1 != make_pair(-1, -1)) {
//         ret.first = min(ret.first, r1.first);
//         ret.second = max(ret.second, r1.second);
//     }
//     pair<int, int> r2 = search(mid + 1, r, diff);
//     if (r2 != make_pair(-1, -1)) {
//         ret.first = min(ret.first, r2.first);
//         ret.second = max(ret.second, r2.second);
//     }
//     return ret;
// }

void secondRun() {
    int n, x;
    cin >> n >> x;
    int ans = -1;

    int jump = 1;
    while (jump * 2 <= n - 1) jump *= 2;
    int best = 0;
    while (jump) {
        if (best + jump < n) {
            int response = query(0, best + jump);
            if (response < n - 1) {
                best += jump;
            }
        }
        jump /= 2;
    }

    int r = best + 1;

    jump = 1;
    while (jump * 2 <= n - 1) jump *= 2;
    best = n - 1;
    while (jump) {
        if (best - jump >= 0) {
            int response = query(best - jump, n - 1);
            if (response < n - 1) {
                best -= jump;
            }
        }
        jump /= 2;
    }

    int l = best - 1;

    assert(l < r);

    if (x)
        ans = l;
    else
        ans = r;

    cout << "! " << ans + 1 << endl;
}

void solve([[maybe_unused]] int test) {
    string run;
    cin >> run;
    if (run == "first") {
        firstRun();
    } else {
        int t;
        cin >> t;
        for (int tt = 1; tt <= t; tt++) {
            secondRun();
        }
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
