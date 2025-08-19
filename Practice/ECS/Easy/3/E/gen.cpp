// Todo: make a better generator, eventually
#include "bits/stdc++.h"
#include "custom/debugger.h"
using namespace std;

int rand(int a, int b) { return a + rand() % (b - a + 1); }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());  // NOLINT

// generate vector of a particular size with values between start and end,
// inclusive
vector<int> generate_vector(int start, int end, int size) {
    vector<int> temp(size);
    for (int i = 0; i < size; i++) {
        int x = rand(start, end);
        temp[i] = x;
    }
    return temp;
}

// generate a permuation of a particular size
vector<int> generate_permutation(int size) {
    vector<int> temp(size);
    for (int i = 0; i < size; i++) temp[i] = i + 1;
    shuffle(temp.begin(), temp.end(), rng);
    return temp;
}

// print a vector, in its entirety
void print_vector(vector<int>& v) {
    for (auto x : v) printf("%d ", x);
    printf("\n");
}

class dsu {
   public:
    vector<int> p, size;
    int n;
    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        size.resize(n, 1);
    }
    int parent(int x) {
        // path compression
        if (x == p[x])
            return x;
        else
            return p[x] = parent(p[x]);
    }
    inline bool unite(int x, int y) {
        x = parent(x);
        y = parent(y);
        if (x != y) {
            if (size[x] > size[y]) swap(x, y);
            p[x] = y;
            size[y] += size[x];
            return true;
        }
        return false;
    }
};

bool connected(int n, vector<pair<int, int>> e) {
    dsu d(n);
    for (auto edge : e) {
        d.unite(edge.first, edge.second);
    }
    for (int i = 1; i < n; i++) {
        if (d.parent(i) != d.parent(0)) return false;
    }
    return true;
}

int main([[maybe_unused]] int argc, char* argv[]) {
    srand(atoi(argv[1]));
    // test cases
    printf("1\n");
    int n = rand(2, 6);
    set<pair<int, int>> s;
    printf("%d", n);
    int m = rand(n - 1, n * (n - 1) / 2);
    printf(" %d", m);
    printf("\n");
    vector<pair<int, int>> e;
    set<int> used;
    for (int i = 1; i < n; i++) {
        int other = rand(0, i - 1);
        s.insert({i + 1, other + 1});
        s.insert({other + 1, i + 1});
        e.push_back({i, other});
    }
    for (int i = n - 1; i < m; i++) {
        // to make x unique, uncomment the following
        // do {
        // x = rand (1, 100);
        // } while (used.count (x));
        // used.insert (x);
        int x, y;
        do {
            x = rand(1, n);
            y = rand(1, n);
        } while (x == y || s.count({x, y}));
        s.insert({x, y});
        s.insert({y, x});
        e.push_back({x - 1, y - 1});
    }

    assert(connected(n, e));

    for (auto edge : e) {
        printf("%d %d\n", edge.first + 1, edge.second + 1);
    }
}
