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

  int a, b;
  cin >> a >> b;
  int years = 0;
  while (a <= b) {
    a = a * 3;
    b = b * 2;
    years++;
  }
  cout << years << "\n";
  return 0;
}
