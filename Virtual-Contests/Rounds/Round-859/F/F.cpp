#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    int i1, j1, i2, j2;
    scanf("%lld%lld%lld%lld", &i1, &j1, &i2, &j2);
    string d;
    cin >> d;
    int x = 1, y = 1;
    if (d == "DL")
        y = -1;
    else if (d == "UR")
        x = -1;
    else if (d == "UL") {
        x = -1;
        y = -1;
    }
    int i = i1, j = j1;
    int sx = -1, sy = -1;
    bool found = false;
    int cnt = 0;
    int bounces = 0;
    while (1) {
        bool cur = true;
        int diff = i2 - i;
        if (diff * x < 0) cur = false;
        diff = abs(diff);
        int diff2 = j2 - j;
        if (diff2 * y < 0) cur = false;
        diff2 = abs(diff2);
        if (diff != diff2) cur = false;
        int hor = x == -1 ? i - 1 : n - i;
        int ver = y == -1 ? j - 1 : m - j;
        int dist = min(hor, ver);
        int choice = hor < ver;
        i += dist * x;
        j += dist * y;
        if (sx == -1) {
            sx = i;
            sy = j;
        }
        if (diff > dist) cur = false;
        if (cur) {
            found = true;
            break;
        }
        bounces++;
        if (hor == ver) {
            x = -x;
            y = -y;
        } else if (!choice)
            y *= -1;
        else
            x *= -1;
        if (i == sx && j == sy) {
            cnt++;
            if (cnt == 6) break;
        }
    }
    if (found)
        printf("%lld\n", bounces);
    else
        printf("-1\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
