// Todo: make a better generator, eventually
#include "bits/stdc++.h"
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

int main([[maybe_unused]] int argc, char* argv[]) {
    srand(atoi(argv[1]));
    // test cases
    printf("1\n");
    int n = rand(1, 10);
    int m = rand(1, 10);
    do {
        n = rand(1, 10);
        m = rand(1, 10);
    } while (n * m < 3);
    printf("%d", n);
    printf(" %d", m);
    int k = rand(1, (n * m - 1) / 2);
    printf(" %d", k);
    printf("\n");
    set<pair<int, int>> used;
    for (int i = 0; i < k + 1; i++) {
        int x;
        x = rand(1, n);
        int y = rand(1, m);
        // to make x unique, uncomment the following
        do {
            x = rand(1, n);
            y = rand(1, m);
        } while (used.count({x, y}));
        used.insert({x, y});
        printf("%d %d\n", x, y);
    }
    puts("");
}
