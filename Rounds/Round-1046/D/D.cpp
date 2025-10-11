#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX = (int)1e9;
// constexpr int MX = 5;

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int move(char dir, int steps) {
    cout << "? " << dir << " " << steps << endl;
    int response;
    cin >> response;
    return response;
}

void solve([[maybe_unused]] int test) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    pair<int, int> lower = a[0], upper = a[0];
    pair<int, int> bottomleft = {-MX, -MX}, topleft = {-MX, MX};
    for (int i = 0; i < n; i++) {
        int d1 = dist(bottomleft, a[i]);
        int d2 = dist(topleft, a[i]);
        if (d1 < dist(lower, bottomleft)) {
            lower = a[i];
        }
        if (d2 < dist(upper, topleft)) {
            upper = a[i];
        }
    }

    move('D', MX);
    move('D', MX);
    move('L', MX);
    int d1 = move('L', MX);

    move('U', MX);
    move('U', MX);
    move('U', MX);
    int d2 = move('U', MX);

    int yval = 4 * MX - abs(upper.second - lower.second);  // TODO double-check
    int xval = d1 + d2 - yval;
    int X = (xval - abs(upper.first - lower.first)) / 2;
    X = upper.first < lower.first ? upper.first - X
                                  : lower.first - X;  // TODO double-check
    int xdist = upper.first - X;
    int Y = d2 - xdist;
    Y = upper.second + Y;

    X += 2 * MX;
    Y -= 2 * MX;

    cout << "! " << X << " " << Y << endl;
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
