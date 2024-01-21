#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> matrix(5, vector<int>(5));
  pair<int, int> non_zero_index;
  for (int i = 0 ; i < 5; i++){
    for (int j = 0; j < 5; j++){
      cin >> matrix[i][j];
      if (matrix[i][j] == 1) non_zero_index = make_pair(i,j);
    }
  }
  cout << abs(non_zero_index.first - 2) + abs(non_zero_index.second - 2) << "\n";
  return 0;
}
