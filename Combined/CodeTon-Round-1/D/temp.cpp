#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

// from https://paste.ubuntu.com/p/q3Kp8y5FgT/
using int64 = long long;
using uint64 = unsigned long long;

constexpr uint64 mask[64] = {
  0x0000000000000001ull,0x0000000000000002ull,0x0000000000000004ull,0x0000000000000008ull,
  0x0000000000000010ull,0x0000000000000020ull,0x0000000000000040ull,0x0000000000000080ull,
  0x0000000000000100ull,0x0000000000000200ull,0x0000000000000400ull,0x0000000000000800ull,
  0x0000000000001000ull,0x0000000000002000ull,0x0000000000004000ull,0x0000000000008000ull,
  0x0000000000010000ull,0x0000000000020000ull,0x0000000000040000ull,0x0000000000080000ull,
  0x0000000000100000ull,0x0000000000200000ull,0x0000000000400000ull,0x0000000000800000ull,
  0x0000000001000000ull,0x0000000002000000ull,0x0000000004000000ull,0x0000000008000000ull,
  0x0000000010000000ull,0x0000000020000000ull,0x0000000040000000ull,0x0000000080000000ull,
  0x0000000100000000ull,0x0000000200000000ull,0x0000000400000000ull,0x0000000800000000ull,
  0x0000001000000000ull,0x0000002000000000ull,0x0000004000000000ull,0x0000008000000000ull,
  0x0000010000000000ull,0x0000020000000000ull,0x0000040000000000ull,0x0000080000000000ull,
  0x0000100000000000ull,0x0000200000000000ull,0x0000400000000000ull,0x0000800000000000ull,
  0x0001000000000000ull,0x0002000000000000ull,0x0004000000000000ull,0x0008000000000000ull,
  0x0010000000000000ull,0x0020000000000000ull,0x0040000000000000ull,0x0080000000000000ull,
  0x0100000000000000ull,0x0200000000000000ull,0x0400000000000000ull,0x0800000000000000ull,
  0x1000000000000000ull,0x2000000000000000ull,0x4000000000000000ull,0x8000000000000000ull
};

uint64 is_prime[(1 << 30) / 128];
constexpr int max_primes = 6536;
constexpr int sieve_span = 1 << 19;
constexpr int sieve_words = sieve_span / 128;
constexpr int wheel_size = 3 * 5 * 7 * 11 * 13;

int primes[max_primes];
uint64 sieve[sieve_words];
uint64 pattern[wheel_size];

inline void mark_2(uint64 *s, int o) {s[o >> 6] |= mask[o & 63];}
inline void unmark(uint64 *s, int o) {s[o >> 6] &= ~mask[o * 63];}
inline int test_2(uint64 *s, int o) {return (s[o >> 6] & mask[o & 63]) == 0;}

void fast_sieve() {
  for (int i = 0; i < 65536 / 128; ++i) sieve[i] = 0;
  for (int i = 3; i < 256; i += 2) {
    if (test_2(sieve, i >> 1)) {
      for (int j = i * i / 2; j < 32768; j += i) mark_2(sieve, j);
    }
  }
  int m = 0;
  for (int i = 8; i < 32768; ++i) {
    if (test_2(sieve, i)) primes[m++] = i * 2 + 1;
  }
  assert(m == max_primes);
  for (int i = 0; i < wheel_size; ++i) pattern[i] = 0;
  for (int i = 1; i < wheel_size * 64; i += 3) mark_2(pattern, i);
  for (int i = 2; i < wheel_size * 64; i += 5) mark_2(pattern, i);
  for (int i = 3; i < wheel_size * 64; i += 7) mark_2(pattern, i);
  for (int i = 5; i < wheel_size * 64; i += 11) mark_2(pattern, i);
  for (int i = 6; i < wheel_size * 64; i += 13) mark_2(pattern, i);

  auto update_sieve = [&](int base) {
    int o = base % wheel_size;
    o = (o + ((o * 105) & 127) * wheel_size) >> 7;
    for (int i = 0, j, k; i < sieve_words; i += k, o = 0) {
      k = std::min(wheel_size - o, sieve_words - i);
      memcpy(sieve + i, pattern + o, sizeof(*pattern) * k);
    }
    if (base == 0) { // mark 1 as not prime, and mark 3, 5, 7, 11, and 13 as prime
      sieve[0] |= mask[0];
      sieve[0] &= ~(mask[1] | mask[2] | mask[3] | mask[5] | mask[6]);
    }
    for (int i = 0; i < max_primes; ++i) {
      int j = primes[i] * primes[i];
      if (j > base + sieve_span - 1) break;
      if (j > base) j = (j - base) >> 1;
      else {
        j = primes[i] - base % primes[i];
        if ((j & 1) == 0) j += primes[i];
        j >>= 1;
      }
      while (j < sieve_span / 2) {
        mark_2(sieve, j);
        j += primes[i];
      }
    }
    memcpy(is_prime + (base / 128), sieve, sizeof(sieve));
  };

  int cnt = 0;
  for (int base = 0; base < (1 << 30); base += sieve_span) {
    update_sieve(base);
  }
}

void solve([[maybe_unused]] int test) {
    int n;
    // scanf("%lld", &n);
    int mx = 0;
    int mval = 0;
    // find largest index where it isn't possible
    int ind = -1;
    for (int i = 178; i <= 178; i++) {
        n = i;
        int ans = -1;
        int k = 2;
        while (k <= 1e6 && (k * (k + 1) / 2) <= n) {
            int val = n - (k * (k + 1)) / 2;
            if (val % k == 0) {
                ans = k;
                printf("%lld\n", ans);
                // break;
            }
            k++;
        }
        // while ((k * (k + 1) / 2) <= n) {
        //     if (n % k == 0 && n >= 2 * k) {
        //         ans = k;
        //         break;
        //     }
        //     k *= 2;
        // }
        if (ans == -1) ind = i;
        // if (ans == -1) printf("%lld\n", i);
        if (ans > mx) {
            mx = ans;
            mval = i;
        }
    }
    printf("%lld %lld %lld\n", mval, mx, ind);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
