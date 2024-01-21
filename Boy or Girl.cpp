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

  string name;
  cin >> name;
  set<char> unique_chars;
  for (auto x : name) {
    unique_chars.insert(x);
  }
  if (unique_chars.size() % 2 == 0)
    cout << "CHAT WITH HER!\n";
  else
    cout << "IGNORE HIM!\n";
  return 0;
}
