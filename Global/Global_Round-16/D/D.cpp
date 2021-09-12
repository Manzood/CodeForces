#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
const int inf = 1e9 + 7;


bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.second < b.second);
}

struct segtree { // ZERO BASED INDEXING
    int size;
    vector <long long> sum;
    vector <long long> m;
    vector <long long> mx;
    void init (int n) { // just making our size a power of two
        size = 1;
        while (size < n) size *= 2;
        sum.assign(2*size-1, 0);
        m.assign(2*size-1, inf);
        mx.assign(2*size-1, -inf);
    }
    void build (vector <int>& a) {
        int n = a.size();
        int numzeroes = size-n;
        int counter = 0;
        for (int i = 2*size-2; i >= 0; i--) {
            if (counter++ < numzeroes) {
                sum[i] = 0;
                m[i] = inf;
                mx[i] = -inf;
            }
            else if (n > 0) {
                sum[i] = a[--n];
                m[i] = a[n];
                mx[i] = a[n];
            }
            else {
                sum[i] += sum[2*i+1] + sum[2*i+2];
                m[i] = min(m[2*i+1], m[2*i+2]);
                mx[i] = max(mx[2*i+1], mx[2*i+2]);
            }
        }
    }
    void set (int i, int v) { // setting index i to element v
        set (i, v, 0, 0, size);
    }
    void set (int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sum[x] = v;
            m[x] = v;
            mx[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        } else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
        m[x] = min(m[2 * x + 1], m[2 * x + 2]);
        mx[x] = max(mx[2 * x + 1], mx[2 * x + 2]);
        return;
    }
    long long getsum (int left, int right) { // returns sum between indexes [left, right - 1], inclusive
        return getsum(left, right, 0, 0, size);
    }
    long long getsum (int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return 0;
        if (lx >= left && rx <= right) return sum[x];
        int mid = (lx + rx) / 2;
        long long s1 = getsum (left, right, 2 * x + 1, lx, mid);
        long long s2 = getsum (left, right, 2 * x + 2, mid, rx);
        return s1 + s2;
    }
    long long getmin (int left, int right) { // returns min between indexes [left, right - 1], inclusive
        return getmin(left, right, 0, 0, size);
    }
    long long getmin (int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return inf;
        if (lx >= left && rx <= right) return m[x];
        int mid = (lx + rx) / 2;
        long long s1 = getmin (left, right, 2 * x + 1, lx, mid);
        long long s2 = getmin (left, right, 2 * x + 2, mid, rx);
        return min(s1, s2);
    }
    long long getmax (int left, int right) { // returns max between indexes [left, right - 1], inclusive
        return getmax (left, right, 0, 0, size);
    }
    long long getmax (int left, int right, int x, int lx, int rx) {
        if (lx >= right || left >= rx) return -inf;
        if (lx >= left && rx <= right) return mx[x];
        int mid = (lx + rx) / 2;
        long long s1 = getmax (left, right, 2 * x + 1, lx, mid);
        long long s2 = getmax (left, right, 2 * x + 2, mid, rx);
        return max(s1, s2);
    }
};

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%lld%lld", &n, &m);
        // split by row
        vector <vector <int>> a(n, vector <int> (m));
        vector <vector <pair <int, int>>> sorted(n, vector <pair <int, int>> (m));
        vector <vector <pair <int, int>>> A(n, vector <pair <int, int>> (m));
        vector <vector <int>> a_to_sorted(n, vector <int> (m));
        vector <pair <int, int>> temp1 (n * m);
        int row = -1;
        int col = 0;

        for (int i = 0; i < n * m; i++) {
            if (i % m == 0) {
                row++;
                col = 0;
            }
            scanf("%lld", &a[row][col]);
            temp1[i].first = a[row][col];
            temp1[i].second = i;
            // sorted[row][col].first = a[row][col];
            // sorted[row][col].second = col;
            col++;
        }

        sort (temp1.begin(), temp1.end());
        row = -1;
        col = 0;

        for (int i = 0; i < n * m; i++) {
            if (i % m == 0) {
                row++;
                col = 0;
            }
            int ind = 0;
            sorted[row][col].first = temp1[i].first;
            sorted[row][col].second = ind;
            A[row][col].first = temp1[i].first;
            A[row][col].second = temp1[i].second;
            col++;
        }

        for (int i = 0; i < n; i++) {
            sort (A[i].begin(), A[i].end(), sortbysec);
        }

        row = -1;
        col = 0;

        for (int i = 0; i < n * m; i++) {
            if (i % m == 0) {
                row++;
                col = 0;
            }
            sorted[row][col].first = A[row][col].first;
            sorted[row][col].second = col;
            col++;
        }

        // for each index in each row, find the number of values to the left that are less than current value
        for (int i = 0; i < n; i++) {
            sort (sorted[i].begin(), sorted[i].end());
            for (int j = 0; j < m; j++) {
                a_to_sorted[i][sorted[i][j].second] = j;
                if (j > 0 && sorted[i][j].first == sorted[i][j-1].first) {
                    a_to_sorted[i][sorted[i][j].second] = a_to_sorted[i][sorted[i][j-1].second];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            // treat each row independently
            segtree st;
            st.init(m + 1);
            vector <int> temp (m + 1, 0);
            st.build(temp);

            // printf("%lld: ", i);
            for (int j = 0; j < m; j++) {
                // find index in sorted array
                int ind = a_to_sorted[i][j];
                int s = st.getsum (0, ind);
                int val = st.getsum (ind, ind + 1);
                st.set(ind, val + 1);
                // printf("%lld:%lld:%lld ", sorted[i][j].first, s, ind);
                ans += s;
            }
            // printf("\n");
            // debug (ans);
        }
        printf("%lld\n", ans);
    }
}
