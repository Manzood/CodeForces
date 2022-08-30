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
    int n = 5;
    printf("%d", n);
    // int m = rand (2, 10);
    // printf(" %d", m);
    printf("\n");
    vector<int> temp = {0, 1, 2, 3, 4};
    random_shuffle(temp.begin(), temp.end());
    string s = "Timur";
    string out;
    for (int i = 0; i < n; i++) {
        out += s[temp[i]];
    }
    cout << out << "\n";
}
