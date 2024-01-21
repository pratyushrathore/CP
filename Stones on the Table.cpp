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

  int n; cin >> n;
  string s; cin >> s;
  int ans = 0;
  for (int i = 0; i < n - 1; i++){
    if (s[i] == s[i + 1]) ans++;  // effectively, we'll remove s[i]
  }
  cout << ans << "\n";
  return 0;
}
