#include <bits/stdc++.h>
using namespace std;

// For a given parity group of points (each with coordinates U,V)
// (the points are already in the order of increasing original index)
// we want to count the number of pairs (i, j) with i < j such that
//   U(i) <= U(j) - 2   and   V(i) <= V(j) - 2.
// We do this using an “inline” 2D BIT that is built on compressed coordinates.

struct Point {
    int idx;  // original index (order)
    int u;    // U = i - 2*A(i)
    int v;    // V = 2*A(i) + 2*B(i) - i
};

// This function counts the number of pairs for a parity group.
// We inline the BIT code directly in this function.
inline int processParityGroup(const vector<Point>& pts) {
    int m = pts.size();
    if (m == 0) return 0;

    // --- Coordinate compression for U and V.
    vector<int> compU, compV;
    compU.reserve(m);
    compV.reserve(m);
    for (const auto& p : pts) {
        compU.push_back(p.u);
        compV.push_back(p.v);
    }
    sort(compU.begin(), compU.end());
    compU.erase(unique(compU.begin(), compU.end()), compU.end());
    sort(compV.begin(), compV.end());
    compV.erase(unique(compV.begin(), compV.end()), compV.end());

    auto getU = [&](int x) -> int {
        return int(lower_bound(compU.begin(), compU.end(), x) - compU.begin()) +
               1;
    };
    auto getV = [&](int x) -> int {
        return int(lower_bound(compV.begin(), compV.end(), x) - compV.begin()) +
               1;
    };

    int nU = compU.size();
    // Build the 2D BIT structure: for each BIT index from 1 to nU,
    // we store a sorted vector of possible V values.
    vector<vector<int>> bit(nU + 1);
    for (int i = 0; i < m; i++) {
        int cu = getU(pts[i].u);
        // For BIT, update all indices i such that index i covers cu.
        for (int j = cu; j <= nU; j += j & -j) bit[j].push_back(getV(pts[i].v));
    }
    // Sort and remove duplicates in each BIT node.
    for (int i = 1; i <= nU; i++) {
        sort(bit[i].begin(), bit[i].end());
        bit[i].erase(unique(bit[i].begin(), bit[i].end()), bit[i].end());
    }

    // BIT tree: we will maintain a parallel structure of counts.
    vector<vector<int>> fenw(nU + 1);
    for (int i = 1; i <= nU; i++) {
        fenw[i].assign(bit[i].size() + 1, 0);
    }

    auto bit_update = [&](int pos, int v, int delta) {
        // pos: compressed U value, v: compressed V value.
        for (int i = pos; i <= nU; i += i & -i) {
            // Find the position in bit[i] that equals v.
            int idx = int(lower_bound(bit[i].begin(), bit[i].end(), v) -
                          bit[i].begin()) +
                      1;
            for (int j = idx; j < (int)fenw[i].size(); j += j & -j)
                fenw[i][j] += delta;
        }
    };

    auto bit_query = [&](int pos, int v) -> int {
        int res = 0;
        for (int i = pos; i > 0; i -= i & -i) {
            int idx = int(upper_bound(bit[i].begin(), bit[i].end(), v) -
                          bit[i].begin());
            for (int j = idx; j > 0; j -= j & -j) res += fenw[i][j];
        }
        return res;
    };

    // Now process points in order.
    // For each new point j, we want to count how many earlier points i satisfy:
    // U(i) <= U(j)-2  and  V(i) <= V(j)-2.
    int ans = 0;
    for (int j = 0; j < m; j++) {
        int u_thresh = pts[j].u - 2;
        int v_thresh = pts[j].v - 2;
        // Find compressed coordinate for u_thresh.
        int cu_thresh = int(upper_bound(compU.begin(), compU.end(), u_thresh) -
                            compU.begin());
        int cv_thresh = int(upper_bound(compV.begin(), compV.end(), v_thresh) -
                            compV.begin());
        if (cu_thresh > 0 && cv_thresh > 0) {
            ans += bit_query(cu_thresh, cv_thresh);
        }
        // Insert current point into BIT.
        int cu = getU(pts[j].u);
        int cv = getV(pts[j].v);
        bit_update(cu, cv, 1);
    }
    return ans;
}

// For a fixed candidate x, count the number of even-length subarrays that are
// "good" with median x.
inline long long countCandidateEvenGood(const vector<int>& a, int x) {
    int n = a.size();
    vector<int> A(n + 1, 0), B(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        A[i] = A[i - 1] + (a[i - 1] < x);
        B[i] = B[i - 1] + (a[i - 1] == x);
    }
    // Compute prefix arrays:
    //   X(i) = 2*A(i) - i,   Y(i) = 2*A(i) + 2*B(i) - i,
    //   U(i) = -X(i),        V(i) = Y(i).
    vector<int> X(n + 1), Y(n + 1), U(n + 1), V(n + 1);
    for (int i = 0; i <= n; i++) {
        X[i] = 2 * A[i] - i;
        Y[i] = 2 * A[i] + 2 * B[i] - i;
        U[i] = -X[i];
        V[i] = Y[i];
    }
    // Split prefix indices into parity groups.
    vector<Point> ptsEven, ptsOdd;
    ptsEven.reserve(n / 2 + 2);
    ptsOdd.reserve(n / 2 + 2);
    for (int i = 0; i <= n; i++) {
        if (i & 1)
            ptsOdd.push_back({i, U[i], V[i]});
        else
            ptsEven.push_back({i, U[i], V[i]});
    }
    long long cnt = 0;
    cnt += processParityGroup(ptsEven);
    cnt += processParityGroup(ptsOdd);
    return cnt;
}

// Fast I/O.
static inline void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Count odd-length subarrays.
        int evenCount = 0, oddCount = 0;
        for (int i = 0; i <= n; i++) {
            if (i & 1)
                oddCount++;
            else
                evenCount++;
        }
        long long oddSub = (long long)evenCount * oddCount;

        long long evenGood = 0;
        // There are only 10 candidate values.
        for (int x = 1; x <= 10; x++) {
            evenGood += countCandidateEvenGood(a, x);
        }

        cout << oddSub + evenGood << "\n";
    }
    return 0;
}

