// Todo: make a better generator, eventually
#include "bits/stdc++.h"
using namespace std;

int rand(int a, int b) { return a + rand() % (b - a + 1); }

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
    random_shuffle(temp.begin(), temp.end());
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
    int n = rand(2, 10);
    printf("%d", n);
    int m = 10;
    printf(" %d", m);
    printf("\n");
    set<int> used;
    for (int i = 0; i < n; i++) {
        int x;
        x = rand(1, 300);
        // to make x unique, uncomment the following
        // do {
        // x = rand (1, 100);
        // } while (used.count (x));
        // used.insert (x);
        printf("%d ", x);
    }
    printf("\n");
    for (int i = 0; i < m; i++) {
        int x;
        x = rand(1, 500);
        printf("%d\n", x);
    }
}
