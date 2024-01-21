#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string S; cin >> S;
  if (S[0] >= 97) S[0] ^= 32;
  cout << S << "\n";
  return 0;
}
