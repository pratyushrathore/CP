#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  /*
    n = number of messages
    f = Units of charge (initially)
    a = Units of charge lost at each unit of time the phone is turned on
    b = Units of charge lost each time the phone is turned off and then turned
    on again
  */

  int tt;
  cin >> tt;
  while (tt--) {
    long long int n, f, a, b;
    cin >> n >> f >> a >> b;
    vector<int> moments(n + 1);
    for (int i = 0; i < n + 1; i++) {
      if (i == 0)
        moments[i] = 0;
      else
        cin >> moments[i];
    }
    long long int charge = f;
    long long int i = 0;
    while (charge > 0 && i < n) {
      long long int cost1 = (moments[i + 1] - moments[i]) * a;
      long long int cost2 = b;
      if (cost1 < cost2)
        charge -= cost1;
      else
        charge -= cost2;
      i++;
    }
    if (charge <= 0)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
