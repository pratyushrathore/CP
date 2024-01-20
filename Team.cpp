#include <iostream>
#include <vector>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n; cin >> n;
  int n_solved = 0;
  for (int i = 0; i < n; i++){
    bool p, v, t;
    cin >> p >> v >> t;
    if (p&&v || v && t || p && t) n_solved++; 
  }
  cout << n_solved << "\n";
  return 0;
}
