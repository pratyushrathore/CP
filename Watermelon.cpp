#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int w;
  cin >> w;
  // Check if 2a + 2b = w has a solution, i.e. a + b = w/2 , where a, b >= 0 and
  // a,b are both +ve integer effectively, if w/2 is even, then there always
  // exist such a solution, expect for w/2 = 2

  if (w % 2 == 0) {
    if (w == 2)
      cout << "NO\n";
    else
      cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
