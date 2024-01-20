#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve( long int n, long long int m, long long int a) {
  if (a > max(n, m)) {
    cout << 1 << "\n";
  } else if (a >= min(n, m) && a <= max(n, m)) {
    long long int larger_side = max(n, m);
    cout << (int)(larger_side / a) << "\n";
  } else {
    long long int n_x, n_y;
    n_x = (m % a == 0) ? (long long int)(m / a) : (long long int)(m / a) + 1;
    // cout << "n_x = " << n_x << "\n";
    long long int left_length = n - a;
    if (left_length <= 0)
      cout << n_x << "\n";
    else {
      n_y = (left_length % a == 0) ? (long long int)(left_length / a)
                                   : (long long int)(left_length / a) + 1;
      cout << n_x + n_y * n_x << "\n";
    }
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  /*
    n_tiles*a*a >= n*m . We need to cover the whole area
    n = m = 6
    a = 4
    n*m = 36
    a*a = 24
    36/24 = 1.5
  */

  long long int n, m, a;
  cin >> n >> m >> a;
  solve(m, n, a);
  return 0;
}
