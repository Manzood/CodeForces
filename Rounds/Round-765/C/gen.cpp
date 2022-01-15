// Todo: make a better generator, eventually
#include<bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;

int rand(int a, int b) {
	return a + rand() % (b - a + 1);
}

vector <int> generate_vector (int start, int end, int size) {
    vector <int> temp(size);
    set <int> s;
    for (int i = 0; i < size; i++) {
        int x;
        do {
            x = rand (start, end);
        } while (s.count(x));
        s.insert(x);
        temp[i] = x;
    }
    return temp;
}

vector <int> generate_permutation (int size) {
    vector <int> temp(size);
    for (int i = 0; i < size; i++) {
        temp[i] = i + 1;
    }
    random_shuffle (temp.begin(), temp.end());
    return temp;
}

void print_vector (vector <int>& v) {
    for (auto x: v) {
        printf("%d ", x);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
	srand (atoi (argv[1]));
    // test cases
    // printf("1\n");
	int n = rand (2,5);
	printf ("%d", n);
    int l = rand (n + 1, 10);
    printf(" %d", l);
    int k = rand (0, n - 1);
    printf(" %d", k);
    // int m = rand (2, 10);
    // printf(" %d", m);
    printf("\n");
	set <int> used;
    vector<int> pos = generate_vector (0, l - 1, n);
    sort (pos.begin(), pos.end());
    pos[0] = 0;
    print_vector (pos);
    vector<int> limits = generate_vector (1, 10, n);
    print_vector (limits);
	// puts("");
}
