#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void get_req(vector<int>& a, int ind, vector<vector<vector<int>>>& req,
             vector<vector<vector<bool>>>& req_track) {
    int cnt[3] = {0, 0, 0};
    int excess = 0;
    for (int i = 0; i < 3; i++) {
        cnt[a[i]]++;
        if (cnt[a[i]] > 1) excess = a[i];
    }
    for (int i = 0; i < 3; i++) {
        if (cnt[i] == 0) {
            if (!req_track[excess][i][ind]) {
                req_track[excess][i][ind] = true;
                req[excess][i].push_back(ind);
            }
        }
    }
}

vector<vector<int>> ans;
void perform_swap(vector<vector<int>>& a, int i, int j, int v1, int v2) {
    ans.push_back({i, v1, j, v2});
    int ind1 = 0;
    while (a[i][ind1] != v1) ind1++;
    int ind2 = 0;
    while (a[j][ind2] != v2) ind2++;
    swap(a[i][ind1], a[j][ind2]);
    sort(a[i].begin(), a[i].end());
    sort(a[j].begin(), a[j].end());  // might not be necessary
}

void fix_pairs(vector<vector<vector<int>>>& req, vector<vector<int>>& a,
               vector<vector<vector<bool>>>& req_track) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            while ((int)req[i][j].size() > 0 && (int)req[j][i].size() > 0) {
                int f = req[i][j].back();
                int s = req[j][i].back();
                req[i][j].pop_back();
                req[j][i].pop_back();
                req_track[i][j][f] = false;
                req_track[j][i][s] = false;
                perform_swap(a, f, s, i, j);
            }
        }
    }
}

void solve_triples(vector<vector<vector<int>>>& req, vector<vector<int>>& a,
                   vector<vector<vector<bool>>>& req_track) {
    for (int j = 1; j < 3; j++) {
        for (int k = 1; k < 3; k++) {
            while ((int)req[0][j].size() > 0 && (int)req[j][k].size() > 0) {
                int f = req[0][j].back();
                int s = req[j][k].back();
                req[0][j].pop_back();
                req[j][k].pop_back();
                req_track[0][j][f] = false;
                req_track[j][k][s] = false;
                perform_swap(a, f, s, 0, j);
            }
        }
    }
}

void solve([[maybe_unused]] int test) {
    ans.clear();
    int n;
    scanf("%lld", &n);
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 3; j++) {
            if (s[j] == 'w')
                a[i][j] = 0;
            else if (s[j] == 'i')
                a[i][j] = 1;
            else
                a[i][j] = 2;
        }
        sort(a[i].begin(), a[i].end());
    }
    vector<vector<vector<int>>> req(3, vector<vector<int>>(3));
    vector<vector<vector<bool>>> req_track(
        3, vector<vector<bool>>(3, vector<bool>(n, false)));
    for (int i = 0; i < n; i++) {
        get_req(a[i], i, req, req_track);
    }
    // go through requirements fixing pairs
    // once no pairs are possibly fixed
    fix_pairs(req, a, req_track);
    for (int i = 0; i < n; i++) {
        get_req(a[i], i, req, req_track);
    }
    fix_pairs(req, a, req_track);
    for (int i = 0; i < n; i++) {
        get_req(a[i], i, req, req_track);
    }
    // TODO: prove that two iterations are enough
    // solve triples
    solve_triples(req, a, req_track);
    for (int i = 0; i < n; i++) {
        get_req(a[i], i, req, req_track);
    }
    fix_pairs(req, a, req_track);
    printf("%lld\n", (int)ans.size());
    map<int, char> mp = {{0, 'w'}, {1, 'i'}, {2, 'n'}};
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%lld %c %lld %c\n", ans[i][0] + 1, mp[ans[i][1]], ans[i][2] + 1,
               mp[ans[i][3]]);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
