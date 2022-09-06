#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<pair<int, int>> eight_dirs = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                                     {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

vector<vector<bool>> marked;

bool check_surroundings(int i, int j, int param, vector<string>& grid) {
    bool retval = true;
    int x, y;
    int n = grid.size();
    int m = grid[0].size();
    if (param == 1) {
        x = i - 1;
        y = j - 1;
    } else if (param == 2) {
        x = i - 1;
        y = j + 2;
    } else if (param == 3) {
        x = i + 2;
        y = j - 1;
    } else {
        x = i + 2;
        y = j + 2;
    }
    int cur_x = i - 1;
    for (int cur_y = j - 1; cur_y <= j + 2; cur_y++) {
        if (ok(cur_x, cur_y, n, m) && !(cur_x == x && cur_y == y) &&
            grid[cur_x][cur_y] == '*') {
            return false;
        }
    }
    cur_x = i + 2;
    for (int cur_y = j - 1; cur_y <= j + 2; cur_y++) {
        if (ok(cur_x, cur_y, n, m) && !(cur_x == x && cur_y == y) &&
            grid[cur_x][cur_y] == '*') {
            return false;
        }
    }
    int cur_y = j - 1;
    for (cur_x = i - 1; cur_x <= i + 2; cur_x++) {
        if (ok(cur_x, cur_y, n, m) && !(cur_x == x && cur_y == y) &&
            grid[cur_x][cur_y] == '*') {
            return false;
        }
    }
    cur_y = j + 2;
    for (cur_x = i - 1; cur_x <= i + 2; cur_x++) {
        if (ok(cur_x, cur_y, n, m) && !(cur_x == x && cur_y == y) &&
            grid[cur_x][cur_y] == '*') {
            return false;
        }
    }
    return retval;
}

int check_quadrant(int i, int j, vector<string>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    cnt += (grid[i][j] == '*') + (i + 1 < n && grid[i + 1][j] == '*') +
           (j + 1 < m && grid[i][j + 1] == '*') +
           (i + 1 < n && j + 1 < m && grid[i + 1][j + 1] == '*');
    if (cnt == 3) {
        if (grid[i][j] == '*') marked[i][j] = true;
        if (i + 1 < n && grid[i + 1][j] == '*') marked[i + 1][j] = true;
        if (j + 1 < m && grid[i][j + 1] == '*') marked[i][j + 1] = true;
        if (i + 1 < n && j + 1 < m && grid[i + 1][j + 1] == '*')
            marked[i + 1][j + 1] = true;
        if (grid[i][j] == '.')
            return 1;
        else if (grid[i][j + 1] == '.')
            return 2;
        else if (grid[i + 1][j] == '.')
            return 3;
        else
            return 4;
    }
    // if (i == 0 && j == 7) debug(cnt);
    return -1;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    marked.resize(n);
    marked.assign(n, vector<bool>(m, false));

    bool ans = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val = check_quadrant(i, j, grid);
            if (val != -1) {
                ans &= check_surroundings(i, j, val, grid);
            }
            // debug(i, j, val, ans);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*' && marked[i][j] == false) {
                ans = false;
            }
        }
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
