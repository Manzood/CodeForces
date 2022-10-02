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
    int n = rand(2, 4);
    printf("%d", n);
    // int m = rand (2, 10);
    // printf(" %d", m);
    printf("\n");
    vector<int> a = generate_permutation(n);
    int k = rand(0, n);
    vector<int> out(n);
    int l1 = n + 1, l2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= k) {
            out[a[i] - 1] = l1;
            l2 = a[i];
        } else {
            out[a[i] - 1] = l2;
            l1 = a[i];
        }
    }
    for (auto x : out) {
        printf("%d ", x);
    }
    puts("");
    printf("%d\n", k);
    for (auto x : a) {
        printf("%d ", x);
    }
    puts("");
}
