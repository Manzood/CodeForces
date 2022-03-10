#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int inf = 1e18;

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

struct point {
    int x;
    int y;
};

int manhattan(point a, point b) {
    return (abs(a.x - b.x) + abs(a.y - b.y));
}

// check for visited
point getclosest (point cur, set <pair <int, int>>& forbidden, set <pair <int, int>>& visited, map <pair <int, int>, pair <int, int>>& best) {
    point retval = cur;
    visited.insert({cur.x, cur.y});
    if (!forbidden.count({cur.x, cur.y})) {
        best[{cur.x, cur.y}] = {cur.x, cur.y};
        return cur;
    }
    int smallest = inf;
    for (auto d: dirs) {
        point newpoint;
        newpoint.x = cur.x + d[0];
        newpoint.y = cur.y + d[1];
        point closest;
        if (visited.count({newpoint.x, newpoint.y})) {
            closest.x = best[{newpoint.x, newpoint.y}].first;
            closest.y = best[{newpoint.x, newpoint.y}].second;
        } else {
            closest = getclosest(newpoint, forbidden, visited, best);
        }
        if (manhattan(closest, cur) < smallest) {
            retval = closest;
            smallest = manhattan(closest, cur);
        }
    }
    best[{cur.x, cur.y}] = {retval.x, retval.y};
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector <point> a(n);
    set <pair <int, int>> forbidden;
    set <pair <int, int>> visited;
    map <pair<int, int>, pair <int, int>> best;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].x, &a[i].y);
        forbidden.insert({a[i].x, a[i].y});
    }
    for (int i = 0; i < n; i++) {
        point ans = getclosest(a[i], forbidden, visited, best);
        printf("%lld %lld\n", ans.x, ans.y);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
